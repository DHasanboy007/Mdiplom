import matplotlib.pyplot as plt
import matplotlib.patches as patches

# Настройка размера рисунка и белого фона
fig, ax = plt.subplots(figsize=(14, 8), facecolor='white')
ax.set_xlim(0, 15)
ax.set_ylim(0, 8)
ax.axis('off')

# --- СТИЛЬ И ЦВЕТОВАЯ ПАЛИТРА ---
FONT_NAME = 'DejaVu Sans'
COLOR_BLUE_BG = '#E6F0FA'
COLOR_BLUE_BORDER = '#004080'
COLOR_GRAY_BG = '#F0F0F0'
COLOR_GRAY_BORDER = '#555555'

# --- 1. ВНЕШНЯЯ РАМКА СИСТЕМЫ (ОБЩИЙ ВИД) ---
system_box = patches.Rectangle((0.5, 0.8), 14, 6.8, linewidth=1, edgecolor='#CCCCCC', facecolor='#FFFFFF', zorder=1)
ax.add_patch(system_box)
ax.text(0.7, 7.3, "АВТОМАТИЗИРОВАННАЯ ИЗМЕРИТЕЛЬНАЯ СИСТЕМА НА БАЗЕ ИНТЕРФЕЙСА UART-GPIB", fontsize=11, fontweight='bold', fontname=FONT_NAME)

# --- 2. ОРИСОВКА ОСНОВНЫХ БЛОКОВ ---
# Repka Pi 3 (Управляющий компьютер / Хост)
host_box = patches.FancyBboxPatch((1, 3.5), 2.2, 1.6, boxstyle="round,pad=0.1", linewidth=2, edgecolor=COLOR_BLUE_BORDER, facecolor=COLOR_BLUE_BG, zorder=2)
ax.add_patch(host_box)
ax.text(2.1, 4.4, "Микрокомпьютер\nRepka Pi 3\n(ОС Linux)", ha='center', va='center', fontsize=10, fontweight='bold', fontname=FONT_NAME)

# ATmega48 (Мост / Контроллер интерфейса)
bridge_box = patches.FancyBboxPatch((4.7, 3.5), 2.2, 1.6, boxstyle="round,pad=0.1", linewidth=2, edgecolor=COLOR_GRAY_BORDER, facecolor=COLOR_GRAY_BG, zorder=2)
ax.add_patch(bridge_box)
ax.text(5.8, 4.4, "Микроконтроллер\nATmega48\n(Мост UART-GPIB)", ha='center', va='center', fontsize=10, fontweight='bold', fontname=FONT_NAME)

# Магистраль IEEE-488 / GPIB BUS
bus_box = patches.Rectangle((8.3, 1.5), 1.2, 5.2, linewidth=3, edgecolor=COLOR_BLUE_BORDER, facecolor='#FFFFFF', zorder=2)
ax.add_patch(bus_box)
ax.text(8.9, 4.1, "МАГИСТРАЛЬ IEEE-488 / GPIB\n(Параллельный интерфейс)", ha='center', va='center', fontsize=10, fontweight='bold', fontname=FONT_NAME, rotation=90)

# --- 3. РАМКА ЛАБОРАТОРНОГО ОБОРУДОВАНИЯ ---
inst_group = patches.Rectangle((10.7, 1.1), 3.5, 5.9, linewidth=1, linestyle='--', edgecolor='#999999', facecolor='#F9F9F9', zorder=1)
ax.add_patch(inst_group)
ax.text(10.9, 6.7, "Лабораторное оборудование", fontsize=10, style='italic', fontname=FONT_NAME)

# Keithley 2000
inst1 = patches.Rectangle((11.2, 5.0), 2.5, 0.9, linewidth=1.5, edgecolor=COLOR_BLUE_BORDER, facecolor='#FFFFFF', zorder=2)
ax.add_patch(inst1)
ax.text(12.45, 5.45, "Keithley 2000\nЦифровой мультиметр", ha='center', va='center', fontsize=9, fontname=FONT_NAME)

# Keithley 6430
inst2 = patches.Rectangle((11.2, 3.6), 2.5, 0.9, linewidth=1.5, edgecolor=COLOR_BLUE_BORDER, facecolor='#FFFFFF', zorder=2)
ax.add_patch(inst2)
ax.text(12.45, 4.05, "Keithley 6430\nСубфемтоамперный\nисточник-измеритель (SMU)", ha='center', va='center', fontsize=8.5, fontname=FONT_NAME)

# SR850 Lock-In
inst3 = patches.Rectangle((11.2, 2.2), 2.5, 0.9, linewidth=1.5, edgecolor=COLOR_BLUE_BORDER, facecolor='#FFFFFF', zorder=2)
ax.add_patch(inst3)
ax.text(12.45, 2.65, "SR850\nСинхронный\nусилитель (Lock-In)", ha='center', va='center', fontsize=9, fontname=FONT_NAME)

# --- 4. СОЕДИНИТЕЛЬНЫЕ СТРЕЛКИ И ПОДПИСИ ---
# Repka Pi 3 -> ATmega48
ax.annotate('', xy=(4.6, 4.3), xytext=(3.3, 4.3), arrowprops=dict(arrowstyle="-|>", color=COLOR_BLUE_BORDER, lw=2, mutation_scale=15))
ax.text(3.95, 4.5, "Интерфейс UART\n115200 бод\nЛинии TX / RX", ha='center', va='bottom', fontsize=8, color='#333333', fontname=FONT_NAME)

# ATmega48 -> GPIB BUS
ax.annotate('', xy=(8.2, 4.3), xytext=(7.0, 4.3), arrowprops=dict(arrowstyle="-|>", color=COLOR_GRAY_BORDER, lw=2, mutation_scale=15))
ax.text(7.6, 4.5, "Сигналы квитирования\n(Handshake)\n& Линии данных", ha='center', va='bottom', fontsize=8, color='#333333', fontname=FONT_NAME)

# GPIB BUS -> Keithley 2000
ax.annotate('', xy=(11.1, 5.45), xytext=(9.6, 5.45), arrowprops=dict(arrowstyle="-|>", color=COLOR_BLUE_BORDER, lw=1.5, mutation_scale=12))
# GPIB BUS -> Keithley 6430
ax.annotate('', xy=(11.1, 4.05), xytext=(9.6, 4.05), arrowprops=dict(arrowstyle="-|>", color=COLOR_BLUE_BORDER, lw=1.5, mutation_scale=12))
# GPIB BUS -> SR850
ax.annotate('', xy=(11.1, 2.65), xytext=(9.6, 2.65), arrowprops=dict(arrowstyle="-|>", color=COLOR_BLUE_BORDER, lw=1.5, mutation_scale=12))

# --- 5. ПОЯСНЕНИЕ НАПРАВЛЕНИЯ ДАННЫХ (ПОДВАЛ) ---
flow_text = r"$\mathbf{Поток\ данных:}$ Команды SCPI $\rightarrow$ Интерфейс UART $\rightarrow$ Преобразование протокола в ATmega48 $\rightarrow$ Квитирование GPIB $\rightarrow$ Приборы"
ax.text(0.5, 0.3, flow_text, fontsize=9.5, color='#222222', fontname=FONT_NAME)

# Вывод графика на экран
plt.tight_layout()

# Для сохранения расскомментируйте строку ниже:
# plt.savefig('uart_gpib_system_ru.png', dpi=300, bbox_inches='tight')

plt.show()
