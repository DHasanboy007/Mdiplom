import matplotlib.pyplot as plt
import matplotlib.patches as patches
import numpy as np

# Очистка графической памяти перед выводом
plt.clf()
plt.close('all')

# Rasm o'lchami va oq fonni eng ideal formatda sozlash
fig, ax = plt.subplots(figsize=(16, 9), facecolor='white')
ax.set_xlim(0, 16)
ax.set_ylim(0, 8)
ax.axis('off')

# --- STYLE AND COLOR PALETTE (IEEE / GOST) ---
FONT_NAME = 'DejaVu Sans'
COLOR_BLUE_BG = '#E6F0FA'
COLOR_BLUE_BORDER = '#004080'
COLOR_GRAY_BG = '#F5F5F5'
COLOR_GRAY_BORDER = '#555555'
COLOR_DARK_PANEL = '#1A252C'

# --- 1. TIZIM TASHQI RAMKASI ---
system_box = patches.Rectangle((0.2, 0.6), 15.6, 7.0, linewidth=1.2, edgecolor='#CCCCCC', facecolor='#FFFFFF', zorder=1)
ax.add_patch(system_box)
ax.text(0.5, 7.2, "АВТОМАТИЗИРОВАННАЯ ИЗМЕРИТЕЛЬНАЯ СИСТЕМА НА БАЗЕ ИНТЕРФЕЙСА UART-GPIB", fontsize=12, fontweight='bold', fontname=FONT_NAME)

# --- 2. ULTRA-IDEAL REPCA PI 3 PLATASI ---
# Yaxshilangan yashil muhandislik tekstoliti (PCB)
ax.add_patch(patches.FancyBboxPatch((0.6, 3.2), 2.4, 2.0, boxstyle="round,pad=0.05", linewidth=2, edgecolor='#0E6251', facecolor='#E8F8F5', zorder=2))
# Plataning burchaklaridagi o'rnatish teshiklari (Mounting Holes)
for hx, hy in [(0.8, 3.4), (0.8, 5.0), (2.8, 3.4), (2.8, 5.0)]:
    ax.add_patch(patches.Circle((hx, hy), 0.06, facecolor='#FFFFFF', edgecolor='#0E6251', lw=1, zorder=3))
    ax.add_patch(patches.Circle((hx, hy), 0.03, facecolor='#BDC3C7', zorder=4))
# USB / LAN portlar bloki
ax.add_patch(patches.Rectangle((0.45, 4.4), 0.25, 0.45, facecolor='#BDC3C7', edgecolor='#7F8C8D', lw=1.2, zorder=3)) 
ax.add_patch(patches.Rectangle((0.45, 3.6), 0.25, 0.45, facecolor='#D5DBDB', edgecolor='#7F8C8D', lw=1.2, zorder=3)) 
# Pastki tomondagi Type-C quvvat va micro-HDMI portlari
ax.add_patch(patches.Rectangle((0.9, 3.08), 0.25, 0.15, facecolor='#34495E', edgecolor='black', zorder=3))
ax.add_patch(patches.Rectangle((1.3, 3.08), 0.3, 0.15, facecolor='#BDC3C7', edgecolor='black', zorder=3))
# Markaziy Protsessor (Allwinner SoC) va RAM chipi
ax.add_patch(patches.Rectangle((1.3, 4.2), 0.6, 0.6, facecolor='#2C3E50', edgecolor='black', lw=1, zorder=3))
ax.text(1.6, 4.5, "SoC", color='white', ha='center', va='center', fontsize=8, fontweight='bold')
ax.add_patch(patches.Rectangle((1.4, 3.6), 0.4, 0.4, facecolor='#4D5656', edgecolor='black', lw=0.5, zorder=3))
ax.text(1.6, 3.8, "RAM", color='white', ha='center', va='center', fontsize=7)
# 40-Pin Oltin rangli GPIO konnektori
ax.add_patch(patches.Rectangle((2.75, 3.3), 0.15, 1.8, facecolor='#17202A', edgecolor='black', lw=0.5, zorder=3))
for yp in np.linspace(3.4, 5.0, 15):
    ax.add_patch(patches.Circle((2.8, yp), 0.02, facecolor='#D4AF37', zorder=4))
    ax.add_patch(patches.Circle((2.85, yp), 0.02, facecolor='#D4AF37', zorder=4))
ax.text(1.8, 4.9, "Repka Pi 3\n(ОС Linux)", ha='center', fontsize=9.5, fontweight='bold', fontname=FONT_NAME)

# --- 3. PROFESSIONAL KONTROLLER: ATmega48 ---
ax.add_patch(patches.FancyBboxPatch((4.5, 3.2), 2.2, 2.0, boxstyle="round,pad=0.05", linewidth=2, edgecolor=COLOR_GRAY_BORDER, facecolor=COLOR_GRAY_BG, zorder=2))
# DIP metall oyoqchalari (Pins)
for y_pin in np.linspace(3.4, 5.0, 9):
    ax.add_patch(patches.Rectangle((4.32, y_pin), 0.2, 0.08, facecolor='#7F8C8D', edgecolor='black', lw=0.5, zorder=1))
    ax.add_patch(patches.Rectangle((6.68, y_pin), 0.2, 0.08, facecolor='#7F8C8D', edgecolor='black', lw=0.5, zorder=1))
ax.text(5.6, 4.2, "ATmega48\nКонтроллер\n(Мост UART-GPIB)", ha='center', va='center', fontsize=10, fontweight='bold', fontname=FONT_NAME)

# --- 4. РЕАЛИСТИЧНЫЙ ИНТЕРФЕЙС GPIB (РЕАЛЬНЫЕ КОНТАКТЫ) ---
# Вертикальный кабель шины
ax.add_patch(patches.Rectangle((8.3, 1.1), 0.5, 5.8, facecolor='#2E4053', edgecolor=COLOR_BLUE_BORDER, lw=1.5, zorder=2))
# 24-контактный разъем Centronics IEEE-488
ax.add_patch(patches.Rectangle((8.1, 2.3), 0.9, 3.4, facecolor='#BDC3C7', edgecolor='#7F8C8D', lw=2, zorder=3))
# Металлические защелки разъема
ax.add_patch(patches.Rectangle((7.95, 5.3), 0.15, 0.2, facecolor='#7F8C8D', edgecolor='black', lw=0.5, zorder=4))
ax.add_patch(patches.Rectangle((7.95, 2.5), 0.15, 0.2, facecolor='#7F8C8D', edgecolor='black', lw=0.5, zorder=4))
# Внутреннее пластиковое основание (колодка)
ax.add_patch(patches.Rectangle((8.2, 2.5), 0.7, 3.0, facecolor='#111111', zorder=4))
# Отрисовка 24-х реальных позолоченных контактов (Pins) внутри разъема
for yp in np.linspace(2.65, 5.35, 12):
    ax.add_patch(patches.Rectangle((8.32, yp), 0.1, 0.05, facecolor='#FFD700', edgecolor='#B7950B', lw=0.3, zorder=5))
    ax.add_patch(patches.Rectangle((8.58, yp), 0.1, 0.05, facecolor='#FFD700', edgecolor='#B7950B', lw=0.3, zorder=5))
# Текст на шине
ax.text(8.55, 4.0, "МАГИСТРАЛЬ IEEE-488 (GPIB)", ha='center', va='center', fontsize=10, fontweight='bold', fontname=FONT_NAME, rotation=90, color='#FFFFFF', zorder=6)

# --- 5. ЛАБОРАТОРНЫЕ ПРИБОРЫ ---
inst_group = patches.Rectangle((10.5, 0.9), 5.1, 6.2, linewidth=1, linestyle='--', edgecolor='#999999', facecolor='#FDFEFE', zorder=1)
ax.add_patch(inst_group)
ax.text(10.7, 6.8, "Лабораторное оборудование", fontsize=10, style='italic', fontname=FONT_NAME)

# Прибор 1: Keithley 2000 Мультиметр
ax.add_patch(patches.Rectangle((10.8, 5.0), 4.5, 1.2, linewidth=1.5, edgecolor=COLOR_BLUE_BORDER, facecolor='#FFFFFF', zorder=2))
ax.add_patch(patches.Rectangle((11.0, 5.6), 2.2, 0.45, facecolor=COLOR_DARK_PANEL, zorder=3)) 
ax.text(11.1, 5.75, "  199.9942 mV DC", color='#00FFCC', fontname='Courier New', fontsize=9, fontweight='bold', zorder=4)
for bx in np.linspace(13.4, 14.9, 4): 
    ax.add_patch(patches.Rectangle((bx, 5.8), 0.18, 0.15, facecolor='#BDC3C7', zorder=3))
    ax.add_patch(patches.Rectangle((bx, 5.5), 0.18, 0.15, facecolor='#BDC3C7', zorder=3))
for b_y in [5.15, 5.35]: 
    ax.add_patch(patches.Circle((15.0, b_y), 0.06, facecolor='red', edgecolor='black', zorder=3))
    ax.add_patch(patches.Circle((14.6, b_y), 0.06, facecolor='black', edgecolor='black', zorder=3))
ax.text(11.0, 5.15, "Keithley 2000 Мультиметр", fontsize=8.5, fontname=FONT_NAME, fontweight='bold')

# Прибор 2: Keithley 6430 Источник-измеритель
ax.add_patch(patches.Rectangle((10.8, 3.5), 4.5, 1.2, linewidth=1.5, edgecolor=COLOR_BLUE_BORDER, facecolor='#FFFFFF', zorder=2))
ax.add_patch(patches.Rectangle((11.0, 4.1), 2.2, 0.45, facecolor=COLOR_DARK_PANEL, zorder=3)) 
ax.text(11.1, 4.25, " I: 1.0543 fA", color='#00FFCC', fontname='Courier New', fontsize=9, fontweight='bold', zorder=4)
ax.add_patch(patches.Circle((14.8, 4.1), 0.25, facecolor='#7F8C8D', edgecolor='black', zorder=3)) 
for bx in np.linspace(13.4, 14.2, 3):
    ax.add_patch(patches.Rectangle((bx, 4.25), 0.18, 0.15, facecolor='#BDC3C7', zorder=3))
ax.text(11.0, 3.65, "Keithley 6430 Источник-измеритель (SMU)", fontsize=8.5, fontname=FONT_NAME, fontweight='bold')

# Прибор 3: SR850 Синхронный усилитель (КООРДИНАТА НАЗВАНИЯ ИСПРАВЛЕНА ВНУТРИ)
ax.add_patch(patches.Rectangle((10.8, 1.1), 4.5, 2.1, linewidth=1.5, edgecolor=COLOR_BLUE_BORDER, facecolor='#FFFFFF', zorder=2))
ax.add_patch(patches.Rectangle((11.0, 1.4), 2.5, 1.5, facecolor='#1A252C', zorder=3)) 
wave_t = np.linspace(11.1, 13.4, 100)
wave_y = 2.15 + 0.4 * np.sin(14 * wave_t)
ax.plot(wave_t, wave_y, color='#FFCC00', lw=1.5, zorder=4)
ax.add_patch(patches.Circle((14.0, 2.5), 0.1, facecolor='#BDC3C7', edgecolor='black', lw=1, zorder=3))
ax.add_patch(patches.Circle((14.0, 1.8), 0.1, facecolor='#BDC3C7', edgecolor='black', lw=1, zorder=3))
ax.add_patch(patches.Circle((14.8, 1.8), 0.1, facecolor='#BDC3C7', edgecolor='black', lw=1, zorder=3))
ax.text(14.0, 2.65, "A-IN", fontsize=7, fontname=FONT_NAME, color='black', ha='center')
ax.text(14.0, 1.95, "B-IN", fontsize=7, fontname=FONT_NAME, color='black', ha='center')
ax.text(14.8, 1.95, "REF", fontsize=7, fontname=FONT_NAME, color='black', ha='center')
# Название прибора перенесено строго внутрь белого прямоугольника корпуса (нижний правый угол)
ax.text(11.0, 1.22, "SR850 DSP Синхронный усилитель", fontsize=8.5, fontname=FONT_NAME, fontweight='bold')

# --- 6. ЧИСТЫЕ ВЕКТОРНЫЕ СТРЕЛКИ (БЕЗ НАДПИСЕЙ И ТЕКСТА) ---
def draw_clean_arrow(x1, y1, x2, y2, color=COLOR_BLUE_BORDER, lw=2.5, style="-|>"):
    ax.annotate('', xy=(x2, y2), xytext=(x1, y1), 
                arrowprops=dict(arrowstyle=style, color=color, lw=lw, mutation_scale=14, shrinkA=0, shrinkB=0), zorder=6)

# Вывод стрелок между блоками
draw_clean_arrow(3.1, 4.2, 4.4, 4.2)
draw_clean_arrow(6.8, 4.2, 8.0, 4.2, color=COLOR_GRAY_BORDER)

# Вывод двунаправленных стрелок от шины GPIB к приборам
draw_clean_arrow(9.1, 5.6, 10.7, 5.6, style="<->")
draw_clean_arrow(9.1, 4.1, 10.7, 4.1, style="<->")
draw_clean_arrow(9.1, 2.1, 10.7, 2.1, style="<->")

plt.tight_layout()

# Сохранение финальной очищенной схемы
plt.savefig('uart_gpib_clean_thesis_system.png', dpi=300, bbox_inches='tight')
plt.show()
