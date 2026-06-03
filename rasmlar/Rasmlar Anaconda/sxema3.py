import matplotlib.pyplot as plt
import matplotlib.patches as patches

# Настройка размера рисунка и белого фона для диссертации
fig, ax = plt.subplots(figsize=(15, 9), facecolor='white')

ax.set_xlim(0, 14)
ax.set_ylim(0, 8)
ax.axis('off')

FONT_NAME = 'DejaVu Sans'

# ==========================================
# 1. МИКРОКОМПЬЮТЕР REPKA PI 3
# ==========================================
repka = patches.Rectangle(
    (1, 2), 3, 4,
    linewidth=2, edgecolor='black', facecolor='#E6F0FA', zorder=2
)
ax.add_patch(repka)

ax.text(2.5, 5.5, "Repka Pi 3", ha='center', fontsize=15, fontweight='bold', fontname=FONT_NAME)
ax.text(2.5, 4.7, "ОС Linux\nБиблиотека wiringRP", ha='center', fontsize=10, fontname=FONT_NAME)
ax.text(2.5, 3.8, "Прямое управление\nпортами GPIO", ha='center', fontsize=10, fontname=FONT_NAME, style='italic')

# Разъем GPIO (GPIO Header)
gpio = patches.Rectangle(
    (3.7, 2.5), 0.2, 3,
    linewidth=1.5, edgecolor='black', facecolor='#555555', zorder=3
)
ax.add_patch(gpio)
ax.text(3.8, 5.6, "GPIO", fontsize=9, fontweight='bold', fontname=FONT_NAME, rotation=270, color='white', ha='center')


# ==========================================
# 2. ЭКСПЕРИМЕНТАЛЬНЫЙ МОДУЛЬ СОПРЯЖЕНИЯ
# ==========================================
buffer_board = patches.Rectangle(
    (5.5, 1.5), 3.2, 5,
    linewidth=2, edgecolor='black', facecolor='#FFFDF0', zorder=2
)
ax.add_patch(buffer_board)

ax.text(7.1, 6.1, "Экспериментальный модуль\nсопряжения GPIO-GPIB", ha='center', fontsize=12, fontweight='bold', fontname=FONT_NAME)

# Буфер данных (Data Buffer)
data_buf = patches.Rectangle(
    (5.9, 4.2), 2.4, 1.1,
    linewidth=1.5, edgecolor='black', facecolor='white', zorder=3
)
ax.add_patch(data_buf)
ax.text(7.1, 4.75, "Шинный трансивер\n74LVC245\n(Линии DIO1-DIO8)", ha='center', va='center', fontsize=9, fontname=FONT_NAME)

# Буфер линий управления (Control Buffer)
ctrl_buf = patches.Rectangle(
    (5.9, 2.2), 2.4, 1.1,
    linewidth=1.5, edgecolor='black', facecolor='white', zorder=3
)
ax.add_patch(ctrl_buf)
ax.text(7.1, 2.75, "Буферные схемы\nЛинии управления\nи квитирования", ha='center', va='center', fontsize=9, fontname=FONT_NAME)


# ==========================================
# 3. РАЗЪЕМ МАГИСТРАЛИ (GPIB CONNECTOR)
# ==========================================
gpib = patches.Rectangle(
    (10.5, 2), 2.2, 4,
    linewidth=2, edgecolor='black', facecolor='#F5F5F5', zorder=2
)
ax.add_patch(gpib)

ax.text(11.6, 5.4, "Интерфейс IEEE-488", ha='center', fontsize=12, fontweight='bold', fontname=FONT_NAME)
ax.text(11.6, 4.6, "Разъем Centronics\n(GPIB Connector)", ha='center', fontsize=10, fontname=FONT_NAME)
ax.text(11.6, 3.0, "24-контактный\nпассивный порт", ha='center', fontsize=9, style='italic', fontname=FONT_NAME)


# ==========================================
# 4. СОЕДИНЕНИЯ, ШЛЕЙФЫ И СТРЕЛКИ (ИСПРАВЛЕНО)
# ==========================================

# А. Соединение: Repka Pi 3 (GPIO) -> Модуль сопряжения
# Шлейф к буферу данных
ax.annotate('', xy=(5.9, 4.8), xytext=(3.9, 4.8), arrowprops=dict(arrowstyle="<->", color='black', lw=1.5, mutation_scale=12))
ax.annotate('', xy=(5.9, 4.4), xytext=(3.9, 4.4), arrowprops=dict(arrowstyle="<->", color='black', lw=1.5, mutation_scale=12))

# Шлейф к буферу управления
ax.annotate('', xy=(5.9, 2.9), xytext=(3.9, 2.9), arrowprops=dict(arrowstyle="<->", color='black', lw=1.5, mutation_scale=12))
ax.annotate('', xy=(5.9, 2.5), xytext=(3.9, 2.5), arrowprops=dict(arrowstyle="<->", color='black', lw=1.5, mutation_scale=12))

ax.text(4.9, 5.0, "Линии ввода-вывода", ha='center', fontsize=8, fontname=FONT_NAME, color='#555555')


# Б. Соединение: Модуль сопряжения -> Разъем GPIB
# Магистраль данных (DIO1-DIO8) - Синий цвет
ax.annotate('', xy=(10.5, 4.75), xytext=(8.3, 4.75), arrowprops=dict(arrowstyle="<->", color='blue', lw=2.5, mutation_scale=14))
ax.text(9.4, 5.0, "Шина данных:\nDIO1 - DIO8\n(Параллельный код)", ha='center', fontsize=9, color='blue', fontweight='bold', fontname=FONT_NAME)

# Магистраль управления и квитирования - Красный цвет
ax.annotate('', xy=(10.5, 2.75), xytext=(8.3, 2.75), arrowprops=dict(arrowstyle="<->", color='red', lw=2.5, mutation_scale=14))
ax.text(9.4, 3.1, "Управление и квитирование:\nDAV, NRFD, NDAC\nATN, IFC, SRQ, REN, EOI", ha='center', fontsize=8.5, color='red', fontweight='bold', fontname=FONT_NAME)


# ==========================================
# 5. НАЗВАНИЕ И ТЕХНИЧЕСКИЙ ПОДВАЛ
# ==========================================
ax.text(
    7, 7.2, 
    "Структурная схема экспериментального контроллера GPIO-GPIB", 
    ha='center', fontsize=16, fontweight='bold', fontname=FONT_NAME
)

ax.text(
    7, 0.8, 
    "Разработано в рамках магистерской диссертации  •  Низкоуровневое программное управление шиной без МК", 
    ha='center', fontsize=9.5, style='italic', fontname=FONT_NAME, color='#444444'
)

plt.tight_layout()

# Строка для автоматического сохранения рисунка в высоком качестве
# plt.savefig('experimental_controller_architecture.png', dpi=300, bbox_inches='tight')

plt.show()
