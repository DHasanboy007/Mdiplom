#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "SR850.h"

/* ================================================================== */
/*  Внутренние вспомогательные функции                                  */
/* ================================================================== */

/*
 * sr850_query — отправить запрос и прочитать ответ.
 *
 * Записывает ответ прибора в buf (не более bufsize-1 символов).
 * Завершает строку нулём.
 * Возвращает количество принятых байт (>=0) или -1 при ошибке.
 */
static int sr850_query(int addr,
                       const char *cmd,
                       char *buf,
                       int   bufsize)
{
    int n;

    GPIB_SendCommand(addr, cmd, (int)strlen(cmd));

    n = GPIB_Read(addr, buf, bufsize - 1);
    if (n < 0)
        n = 0;
    buf[n] = '\0';

    return n;
}

/*
 * sr850_query_float — отправить запрос, вернуть float.
 * При ошибке чтения возвращает 0.0f.
 */
static float sr850_query_float(int addr, const char *cmd)
{
    char buf[SR850_BUF_SIZE];
    sr850_query(addr, cmd, buf, sizeof(buf));
    return (float)atof(buf);
}

/*
 * sr850_query_int — отправить запрос, вернуть int.
 * При ошибке чтения возвращает 0.
 */
static int sr850_query_int(int addr, const char *cmd)
{
    char buf[SR850_BUF_SIZE];
    sr850_query(addr, cmd, buf, sizeof(buf));
    return atoi(buf);
}

/*
 * sr850_send — отправить команду без ожидания ответа.
 * Возвращает результат GPIB_SendCommand.
 */
static int sr850_send(int addr, const char *cmd)
{
    return GPIB_SendCommand(addr, cmd, (int)strlen(cmd));
}

/* ================================================================== */
/*  Инициализация                                                       */
/* ================================================================== */

void InitSR850(int addr)
{
    /* Сброс в заводские настройки */
    sr850_send(addr, "*RST");

    /* Очистка регистров статуса и ошибок */
    sr850_send(addr, "*CLS");

    /* Выбор вывода результатов через GPIB (OUTX 1) */
    sr850_send(addr, "OUTX 1");
}

/* ================================================================== */
/*  Основные измерения                                                  */
/* ================================================================== */

/*
 * GetXSR850 — канал X, В
 * SCPI: OUTP? 1
 */
float GetXSR850(int addr)
{
    return sr850_query_float(addr, "OUTP? 1");
}

/*
 * GetYSR850 — канал Y, В
 * SCPI: OUTP? 2
 */
float GetYSR850(int addr)
{
    return sr850_query_float(addr, "OUTP? 2");
}

/*
 * GetRSR850 — амплитуда R, В
 * SCPI: OUTP? 3
 */
float GetRSR850(int addr)
{
    return sr850_query_float(addr, "OUTP? 3");
}

/*
 * GetThetaSR850 — фаза θ, градусы
 * SCPI: OUTP? 4
 */
float GetThetaSR850(int addr)
{
    return sr850_query_float(addr, "OUTP? 4");
}

/* ================================================================== */
/*  Курсор                                                              */
/* ================================================================== */

/*
 * GetCURSSR850 — координаты курсора
 * SCPI: CURS? n  →  "x,y"
 *
 * Ответ прибора: два числа через запятую, например "0.001234,-0.000567"
 * Возвращает 0 при успехе, -1 если запятая не найдена.
 */
int GetCURSSR850(int addr, int cursor, float *x, float *y)
{
    char  buf[SR850_BUF_SIZE];
    char  cmd[SR850_BUF_SIZE];
    char *comma;

    sprintf(cmd, "CURS? %d", cursor);
    sr850_query(addr, cmd, buf, sizeof(buf));

    /* Ищем разделитель */
    comma = strchr(buf, ',');
    if (comma == NULL)
        return -1;          /* Неожиданный формат ответа */

    *x = (float)atof(buf);
    *y = (float)atof(comma + 1);

    return 0;
}

/* ================================================================== */
/*  Вспомогательные Get-функции                                         */
/* ================================================================== */

/*
 * GetFreqSR850 — опорная частота, Гц
 * SCPI: FREQ?
 */
float GetFreqSR850(int addr)
{
    return sr850_query_float(addr, "FREQ?");
}

/*
 * GetPhaseSR850 — опорная фаза, градусы
 * SCPI: PHAS?
 */
float GetPhaseSR850(int addr)
{
    return sr850_query_float(addr, "PHAS?");
}

/*
 * GetSensSR850 — код чувствительности (0..26)
 * SCPI: SENS?
 *
 * Таблица кодов (из руководства SR850):
 *   0=2nV, 1=5nV, 2=10nV, ..., 26=1V
 */
int GetSensSR850(int addr)
{
    return sr850_query_int(addr, "SENS?");
}

/*
 * GetOFLTSR850 — код постоянной времени (0..19)
 * SCPI: OFLT?
 *
 * Таблица кодов:
 *   0=10us, 1=30us, 2=100us, ..., 19=30ks
 */
int GetOFLTSR850(int addr)
{
    return sr850_query_int(addr, "OFLT?");
}

/*
 * GetHARMSR850 — номер гармоники (1..19999)
 * SCPI: HARM?
 */
int GetHARMSR850(int addr)
{
    return sr850_query_int(addr, "HARM?");
}

/* ================================================================== */
/*  Вспомогательные Set-функции                                         */
/* ================================================================== */

/*
 * SetFreqSR850 — установить опорную частоту, Гц
 * SCPI: FREQ f
 */
int SetFreqSR850(int addr, float freq)
{
    char cmd[SR850_BUF_SIZE];
    sprintf(cmd, "FREQ %f", freq);
    return sr850_send(addr, cmd);
}

/*
 * SetPhaseSR850 — установить опорную фазу, градусы (-360.00..360.00)
 * SCPI: PHAS p
 */
int SetPhaseSR850(int addr, float phase)
{
    char cmd[SR850_BUF_SIZE];
    sprintf(cmd, "PHAS %f", phase);
    return sr850_send(addr, cmd);
}

/*
 * SetSensSR850 — установить чувствительность (код 0..26)
 * SCPI: SENS i
 */
int SetSensSR850(int addr, int sens)
{
    char cmd[SR850_BUF_SIZE];
    sprintf(cmd, "SENS %d", sens);
    return sr850_send(addr, cmd);
}

/*
 * SetOFLTSR850 — установить постоянную времени (код 0..19)
 * SCPI: OFLT i
 */
int SetOFLTSR850(int addr, int oflt)
{
    char cmd[SR850_BUF_SIZE];
    sprintf(cmd, "OFLT %d", oflt);
    return sr850_send(addr, cmd);
}

/*
 * SetHARMSR850 — установить номер гармоники (1..19999)
 * SCPI: HARM i
 */
int SetHARMSR850(int addr, int harm)
{
    char cmd[SR850_BUF_SIZE];
    sprintf(cmd, "HARM %d", harm);
    return sr850_send(addr, cmd);
}

/* ================================================================== */
/*  Управляющие команды                                                 */
/* ================================================================== */

/* AutoGainSR850  — автоподстройка усиления  (AGAN) */
int AutoGainSR850(int addr)  { return sr850_send(addr, "AGAN"); }

/* AutoPhaseSR850 — автоподстройка фазы      (APHS) */
int AutoPhaseSR850(int addr) { return sr850_send(addr, "APHS"); }

/* AutoRangeSR850 — автовыбор диапазона      (ARSV) */
int AutoRangeSR850(int addr) { return sr850_send(addr, "ARSV"); }

/* AutoScaleSR850 — автомасштаб дисплея      (ASCL) */
int AutoScaleSR850(int addr) { return sr850_send(addr, "ASCL"); }

/* ResetSR850     — сброс настроек           (*RST) */
int ResetSR850(int addr)     { return sr850_send(addr, "*RST"); }

/* ClearSR850     — очистка статуса          (*CLS) */
int ClearSR850(int addr)     { return sr850_send(addr, "*CLS"); }