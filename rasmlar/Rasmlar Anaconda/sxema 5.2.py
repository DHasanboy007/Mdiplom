import matplotlib.pyplot as plt
import matplotlib.patches as patches
import numpy as np

# Очистка графической памяти перед выводом
plt.clf()
plt.close('all')

# Настройка размера рисунка под стандарт диссертации (16:9)
fig, ax = plt.subplots(figsize=(16, 9), facecolor='white')
ax.set_xlim(0, 16)
ax.set_ylim(0, 8)
ax.axis('off')

# --- СТИЛЬ И ЦВЕТОВАЯ ПАЛИТРА ---
FONT_NAME = 'DejaVu Sans'
COLOR_BLUE_BORDER = '#004080'
COLOR_GRAY_BG = '#F5F5F5'
COLOR_GRAY_BORDER = '#555555'
COLOR_DARK_PANEL = '#1A252C'
COLOR_ARROW = '#2C3E50'

# --- 1. БЛОК 1: МИКРОКОМПЬЮТЕР REPKA PI 3 ---
# Текстолитовая плата (PCB)
ax.add_patch(patches.FancyBboxPatch((0.6, 2.5), 2.6, 3.5, boxstyle="round,pad=0.05", linewidth=2.5, edgecolor='#0E6251', facecolor='#E8F8F5', zorder=2))
# Монтажные отверстия
for hx, hy in [(0.8, 2.7), (0.8, 5.8), (3.0, 2.7), (3.0, 5.8)]:
    ax.add_patch(patches.Circle((hx, hy), 0.08, facecolor='#FFFFFF', edgecolor='#0E6251', lw=1, zorder=3))
    ax.add_patch(patches.Circle((hx, hy), 0.04, facecolor='#BDC3C7', zorder=4))
# Коммутационные порты (USB / LAN)
ax.add_patch(patches.Rectangle((0.4, 4.8), 0.35, 0.7, facecolor='#BDC3C7', edgecolor='#7F8C8D', lw=1.2, zorder=3)) 
ax.add_patch(patches.Rectangle((0.4, 3.8), 0.35, 0.7, facecolor='#D5DBDB', edgecolor='#7F8C8D', lw=1.2, zorder=3)) 
# Нижние разъёмы питания и HDMI
ax.add_patch(patches.Rectangle((1.0, 2.38), 0.3, 0.18, facecolor='#34495E', edgecolor='black', zorder=3))
ax.add_patch(patches.Rectangle((1.6, 2.38), 0.35, 0.18, facecolor='#BDC3C7', edgecolor='black', zorder=3))
# Процессор (SoC) с радиатором охлаждения
ax.add_patch(patches.Rectangle((1.3, 4.4), 0.8, 0.8, facecolor='#2C3E50', edgecolor='black', lw=1, zorder=3))
for rx in np.linspace(1.45, 2.15, 5):
    ax.add_patch(patches.Rectangle((rx, 4.45), 0.06, 0.7, facecolor='#1A252C', zorder=4))
ax.text(1.7, 5.4, "Repka Pi 3\n(ОС Linux)", ha='center', fontsize=10, fontweight='bold', fontname=FONT_NAME)
ax.text(1.7, 3.4, "Отечественный\nмикрокомпьютер", ha='center', fontsize=8.5, fontname=FONT_NAME, color='#111111')
# 40-Pin GPIO разъем
ax.add_patch(patches.Rectangle((3.05, 2.9), 0.15, 2.7, facecolor='#17202A', edgecolor='black', lw=0.5, zorder=3))
for yp in np.linspace(3.0, 5.5, 20):
    ax.add_patch(patches.Circle((3.1, yp), 0.025, facecolor='#D4AF37', zorder=4))
    ax.add_patch(patches.Circle((3.15, yp), 0.025, facecolor='#D4AF37', zorder=4))

# --- СВЯЗЬ 1: ИНТЕРФЕЙС UART (Строго по центру горизонтальной оси) ---
ax.annotate('', xy=(4.4, 4.25), xytext=(3.3, 4.25), arrowprops=dict(arrowstyle='<->', color=COLOR_ARROW, lw=2.0, mutation_scale=15))

# --- 2. БЛОК 2: КОНТРОЛЛЕР UART-GPIB ---
ax.add_patch(patches.FancyBboxPatch((4.5, 2.8), 2.3, 2.9, boxstyle="round,pad=0.05", linewidth=2, edgecolor=COLOR_GRAY_BORDER, facecolor=COLOR_GRAY_BG, zorder=2))
# Корпус микросхемы ATmega48 (DIP)
ax.add_patch(patches.Rectangle((4.8, 3.3), 1.7, 2.0, facecolor='#2C3E50', edgecolor='black', lw=1, zorder=3))
ax.text(5.65, 4.3, "ATmega48", color='white', ha='center', va='center', fontsize=9.5, fontweight='bold', fontname=FONT_NAME)
# Металлические ножки микросхемы
for y_pin in np.linspace(3.5, 5.1, 8):
    ax.add_patch(patches.Rectangle((4.6, y_pin), 0.2, 0.08, facecolor='#BDC3C7', edgecolor='black', lw=0.5, zorder=2))
    ax.add_patch(patches.Rectangle((6.5, y_pin), 0.2, 0.08, facecolor='#BDC3C7', edgecolor='black', lw=0.5, zorder=2))
ax.text(5.65, 3.0, "Контроллер UART-GPIB\nПреобразование\nUART $\leftrightarrow$ IEEE-488", ha='center', va='center', fontsize=9, fontweight='bold', fontname=FONT_NAME)

# --- СВЯЗЬ 2: ВХОД В ШИНУ GPIB ОТ КОНТРОЛЛЕРА ---
ax.annotate('', xy=(7.4, 4.25), xytext=(6.9, 4.25), arrowprops=dict(arrowstyle='<->', color=COLOR_ARROW, lw=2.0, mutation_scale=15))

# --- 3. РЕАЛИСТИЧНАЯ МАГИСТРАЛЬНАЯ ШИНА IEEE-488 (GPIB) ---
# Вертикальный кабель и экранированная шина данных
ax.add_patch(patches.Rectangle((7.5, 1.8), 0.5, 4.9, facecolor='#2E4053', edgecolor=COLOR_BLUE_BORDER, lw=1.5, zorder=2))
# 24-контактный аппаратный разъем Centronics
ax.add_patch(patches.Rectangle((7.3, 2.8), 0.9, 2.9, facecolor='#BDC3C7', edgecolor='#7F8C8D', lw=2, zorder=3))
# Металлические защёлки фиксации кабеля
ax.add_patch(patches.Rectangle((7.15, 5.4), 0.15, 0.2, facecolor='#7F8C8D', edgecolor='black', lw=0.5, zorder=4))
ax.add_patch(patches.Rectangle((7.15, 3.0), 0.15, 0.2, facecolor='#7F8C8D', edgecolor='black', lw=0.5, zorder=4))
# Внутренняя контактная пластиковая колодка
ax.add_patch(patches.Rectangle((7.4, 3.0), 0.7, 2.5, facecolor='#111111', zorder=4))
# 24 позолоченных контакта (Pins) внутри разъема шины
for yp in np.linspace(3.15, 5.35, 12):
    ax.add_patch(patches.Rectangle((7.52, yp), 0.1, 0.05, facecolor='#FFD700', edgecolor='#B7950B', lw=0.3, zorder=5))
    ax.add_patch(patches.Rectangle((7.78, yp), 0.1, 0.05, facecolor='#FFD700', edgecolor='#B7950B', lw=0.3, zorder=5))

# --- СВЯЗЬ 3: ВЫХОД ИЗ ШИНЫ GPIB В ИЗМЕРИТЕЛЬ ---
ax.annotate('', xy=(8.7, 4.25), xytext=(8.1, 4.25), arrowprops=dict(arrowstyle='<->', color=COLOR_ARROW, lw=2.0, mutation_scale=15))

# --- 4. БЛОК 3: ЛАБОРАТОРНЫЙ ИЗМЕРИТЕЛЬ KEITHLEY 6430 ---
ax.add_patch(patches.Rectangle((8.8, 2.5), 4.4, 3.5, linewidth=2.0, edgecolor=COLOR_BLUE_BORDER, facecolor='#FFFFFF', zorder=2))
# Передняя приборная панель
ax.add_patch(patches.Rectangle((9.0, 4.3), 4.0, 1.5, facecolor=COLOR_DARK_PANEL, zorder=3)) 
# Свечение VFD-дисплея прибора
ax.add_patch(patches.Rectangle((9.1, 4.7), 2.4, 0.8, facecolor='#001111', edgecolor='#00FFCC', lw=0.5, zorder=4))
ax.text(9.2, 5.05, "O:  0.0000  V", color='#00FFCC', fontname='Courier New', fontsize=11, fontweight='bold', zorder=5)
ax.text(9.2, 4.83, "I:  1.0543 fA", color='#FFCC00', fontname='Courier New', fontsize=10, zorder=5)
# Навигационные кнопки управления
for bx in np.linspace(11.7, 12.5, 3):
    ax.add_patch(patches.Rectangle((bx, 5.3), 0.18, 0.15, facecolor='#BDC3C7', zorder=4))
    ax.add_patch(patches.Rectangle((bx, 4.8), 0.18, 0.15, facecolor='#BDC3C7', zorder=4))
# Поворотный эндодер (ручка регулировки)
ax.add_patch(patches.Circle((12.6, 4.45), 0.22, facecolor='#7F8C8D', edgecolor='black', zorder=4))
ax.add_patch(patches.Circle((12.6, 4.45), 0.1, facecolor='#34495E', zorder=5))
# Аналоговые измерительные триаксиальные разъемы
for ch_x in [11.8, 12.5]:
    ax.add_patch(patches.Circle((ch_x, 2.9), 0.15, facecolor='#7F8C8D', edgecolor='black', zorder=3))
    ax.add_patch(patches.Circle((ch_x, 2.9), 0.05, facecolor='black', zorder=4))
ax.text(11.0, 3.8, "Keithley 6430", fontsize=11, fontname=FONT_NAME, fontweight='bold', color=COLOR_BLUE_BORDER, ha='center')
ax.text(11.0, 3.4, "Источник-измеритель (SMU)", fontsize=9.5, fontname=FONT_NAME, color='black', ha='center')

# --- СВЯЗЬ 4: ИЗМЕРЯЕМЫЙ СИГНАЛ (Измерительная L-траектория от Keithley к Батарее) ---
ax.annotate('', xy=(13.6, 3.3), xytext=(11.0, 2.5), 
            arrowprops=dict(arrowstyle="->", color='black', lw=1.8, connectionstyle="angle,angleA=0,angleB=90,rad=0", mutation_scale=15))

# --- 5. БЛОК 4: ОБЪЕКТ ИЗМЕРЕНИЯ (БАТАРЕЯ ПОСТОЯННОГО ТОКА) ---
ax.add_patch(patches.Rectangle((13.7, 2.5), 2.1, 3.5, linewidth=2.0, edgecolor='#C0392B', facecolor='#FDF2E9', zorder=2))
ax.text(14.75, 5.6, "Объект измерения", ha='center', fontsize=10, fontweight='bold', color='#900C3F', fontname=FONT_NAME)
# Графическое символьное обозначение многоэлементной батареи по ГОСТ
y_bat = 3.9
ax.plot([13.9, 14.2], [y_bat, y_bat], color='black', lw=1.2, zorder=3)
ax.plot([14.9, 15.2], [y_bat, y_bat], color='black', lw=1.2, zorder=3)
ax.plot([14.2, 14.2], [y_bat-0.6, y_bat+0.6], color='black', lw=1.5, zorder=3) # Положительный полюс +
ax.plot([14.4, 14.4], [y_bat-0.3, y_bat+0.3], color='black', lw=3.5, zorder=3) # Отрицательный полюс -
ax.plot([14.6, 14.6], [y_bat-0.6, y_bat+0.6], color='black', lw=1.5, zorder=3) # +
ax.plot([14.8, 14.8], [y_bat-0.3, y_bat+0.3], color='black', lw=3.5, zorder=3) # -
ax.plot([14.9, 14.9], [y_bat-0.6, y_bat+0.6], color='black', lw=1.5, zorder=3) # +
ax.text(14.1, y_bat+0.7, "+", fontsize=12, fontweight='bold', color='black')
ax.text(15.0, y_bat+0.7, "-", fontsize=14, fontweight='bold', color='black')
ax.text(14.75, 2.9, "Батарея\nпостоянного тока", ha='center', va='center', fontsize=9, fontname=FONT_NAME)

# --- ИНФОРМАЦИОННЫЙ ШЛЕЙФ ОБРАТНОЙ СВЯЗИ (Замкнутый контур данных) ---
# Физический возврат информации от Объекта напрямую обратно к Repka Pi 3 по общему контуру
ax.plot([14.75, 14.75, 1.9, 1.9], [2.5, 1.3, 1.3, 2.5], color='gray', linestyle='--', linewidth=1.2, zorder=1)
ax.annotate('', xy=(1.9, 2.5), xytext=(1.9, 1.4), arrowprops=dict(arrowstyle='->', color='gray', lw=1.2))

# Сохранение и вывод схемы высокого качества для диссертации
plt.savefig("structural_scheme.png", bbox_inches='tight', dpi=300)
plt.show()
