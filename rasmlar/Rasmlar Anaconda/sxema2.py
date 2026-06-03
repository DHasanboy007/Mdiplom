import matplotlib.pyplot as plt
import matplotlib.patches as patches
import matplotlib.patheffects as path_effects

# Rasm o'lchami va foni (Dissertatsiya standartida - 300 DPI)
fig, ax = plt.subplots(figsize=(16, 10), facecolor='white')
ax.set_xlim(0, 16)
ax.set_ylim(0, 10)
ax.axis('off')

# --- PROFESSIONAL PALITRA (IEEE / Industrial Design) ---
FONT_NAME = 'DejaVu Sans'
COLOR_CTRL_BG = '#F0F7FF'
COLOR_CTRL_BORDER = '#0056B3'
COLOR_DEV_BG = '#F8F9FA'
COLOR_DEV_BORDER = '#495057'

# Shinalarning funktsional ranglari
COLOR_DATA = '#004080'      # To'q ko'k — Ma'lumotlar uchun
COLOR_HANDSHAKE = '#28A745' # Yashil — Kvitirlash (Sinxronizatsiya)
COLOR_MGMT = '#D97706'      # To'q sariq — Boshqaruv

# Soyalar uchun effekt (Bloklarni chiroyli va real ko'rsatish uchun)
shadow = [path_effects.SimpleLineShadow(offset=(2, -2), shadow_color='#22000000', alpha=0.15), path_effects.Normal()]

# Sarlavha
ax.text(0.5, 9.5, "СТРУКТУРНАЯ СХЕМА ИНТЕРФЕЙСА IEEE-488 (GPIB)", fontsize=14, fontweight='bold', fontname=FONT_NAME, color='#212529')

# --- 1. LIDER BLOK: KONTROLLER (Chap tomonda) ---
ctrl_box = patches.FancyBboxPatch((0.5, 1.1), 2.8, 7.1, boxstyle="round,pad=0.1,rounding_size=0.15", linewidth=2.5, edgecolor=COLOR_CTRL_BORDER, facecolor=COLOR_CTRL_BG, zorder=3)
ctrl_box.set_path_effects(shadow)
ax.add_patch(ctrl_box)
ax.text(1.9, 4.65, "КОНТРОЛЛЕР GPIB\n(GPIB Controller)", ha='center', va='center', fontsize=11, fontweight='bold', fontname=FONT_NAME, color=COLOR_CTRL_BORDER)


# --- 2. MARKAZIY QISM: YAXLIT MAGISTRAL (BUS) ---
bus_outer = patches.FancyBboxPatch((4.5, 0.8), 6.0, 8.2, boxstyle="round,pad=0.1,rounding_size=0.1", linewidth=1.5, edgecolor='#6C757D', facecolor='#FCFDFD', zorder=1)
ax.add_patch(bus_outer)
ax.text(7.5, 8.6, "МАГИСТРАЛЬ IEEE-488 / GPIB BUS", ha='center', va='center', fontsize=11, fontweight='bold', fontname=FONT_NAME, color='#212529')

# A. DATA BUS oynasi
data_box = patches.Rectangle((4.8, 6.0), 5.4, 2.2, linewidth=1.5, edgecolor=COLOR_DATA, facecolor='#FFFFFF', zorder=2)
ax.add_patch(data_box)
ax.text(7.5, 7.8, "ШИНА ДАННЫХ (DATA BUS)", ha='center', fontsize=9, fontweight='bold', fontname=FONT_NAME, color=COLOR_DATA)
ax.text(7.5, 6.7, "DIO1   DIO2   DIO3   DIO4   DIO5   DIO6   DIO7   DIO8", ha='center', va='center', fontsize=10, fontweight='bold', fontname=FONT_NAME, color='#343A40')

# B. HANDSHAKE SIGNALS oynasi
hs_box = patches.Rectangle((4.8, 3.5), 5.4, 2.1, linewidth=1.5, edgecolor=COLOR_HANDSHAKE, facecolor='#FFFFFF', zorder=2)
ax.add_patch(hs_box)
ax.text(7.5, 5.2, "КВИТИРОВАНИЕ (HANDSHAKE)", ha='center', fontsize=9, fontweight='bold', fontname=FONT_NAME, color=COLOR_HANDSHAKE)
ax.text(7.5, 4.2, "DAV  |  NRFD  |  NDAC", ha='center', va='center', fontsize=10, fontweight='bold', fontname=FONT_NAME, color='#343A40')

# C. MANAGEMENT SIGNALS oynasi
mgmt_box = patches.Rectangle((4.8, 1.1), 5.4, 2.0, linewidth=1.5, edgecolor=COLOR_MGMT, facecolor='#FFFFFF', zorder=2)
ax.add_patch(mgmt_box)
ax.text(7.5, 2.7, "УПРАВЛЕНИЕ (MANAGEMENT)", ha='center', fontsize=9, fontweight='bold', fontname=FONT_NAME, color=COLOR_MGMT)
ax.text(7.5, 1.7, "ATN   |   IFC   |   REN   |   EOI   |   SRQ", ha='center', va='center', fontsize=10, fontweight='bold', fontname=FONT_NAME, color='#343A40')


# --- 3. O'NG QISM: PERIFERIYA QURILMALARI (Yarim o'qlar bo'yicha moslangan) ---
# Manba (Talker) — To'g'ri chiziqda DATA BUS bilan bir xil balandlikda
talker_box = patches.FancyBboxPatch((11.7, 5.9), 3.8, 2.3, boxstyle="round,pad=0.1,rounding_size=0.15", linewidth=2.5, edgecolor=COLOR_DEV_BORDER, facecolor=COLOR_DEV_BG, zorder=3)
talker_box.set_path_effects(shadow)
ax.add_patch(talker_box)
ax.text(13.6, 7.0, "ИСТОЧНИК\n(Talker Device)", ha='center', va='center', fontsize=11, fontweight='bold', fontname=FONT_NAME, color='#212529')

# Qabul qilgich (Listener) — To'g'ri chiziqda MANAGEMENT bilan bir xil balandlikda
listener_box = patches.FancyBboxPatch((11.7, 1.1), 3.8, 2.3, boxstyle="round,pad=0.1,rounding_size=0.15", linewidth=2.5, edgecolor=COLOR_DEV_BORDER, facecolor=COLOR_DEV_BG, zorder=3)
listener_box.set_path_effects(shadow)
ax.add_patch(listener_box)
ax.text(13.6, 2.2, "ПРИЕМНИК\n(Listener Device)", ha='center', va='center', fontsize=11, fontweight='bold', fontname=FONT_NAME, color='#212529')


# --- 4. IDEAL GORIZONTAL VA YAXLIT PARALLEL SHINA ULANISHLARI ---

# Chap tomondagi Kontroller ulanishlari (Aniq gorizontal va to'g'ri)
ax.annotate('', xy=(4.8, 7.1), xytext=(3.4, 7.1), arrowprops=dict(arrowstyle="<->", color=COLOR_DATA, lw=2.5, mutation_scale=14))
ax.annotate('', xy=(4.8, 4.5), xytext=(3.4, 4.5), arrowprops=dict(arrowstyle="<->", color=COLOR_HANDSHAKE, lw=2.5, mutation_scale=14))
ax.annotate('', xy=(4.8, 2.1), xytext=(3.4, 2.1), arrowprops=dict(arrowstyle="<->", color=COLOR_MGMT, lw=2.5, mutation_scale=14))

# O'ng tomondagi ulanishlar (Xuddi siz bergan birinchi rasmdagidek to'g'ri gorizontal o'qlar)
# Istochknik (Talker) -> Data Bus ulanishi
ax.annotate('', xy=(10.2, 7.1), xytext=(11.7, 7.1), arrowprops=dict(arrowstyle="<->", color=COLOR_DATA, lw=2.5, mutation_scale=14))

# Priemnik (Listener) -> Management Bus ulanishi
ax.annotate('', xy=(10.2, 2.1), xytext=(11.7, 2.1), arrowprops=dict(arrowstyle="<->", color=COLOR_MGMT, lw=2.5, mutation_scale=14))


# --- 5. SIZ XOHLAGAN YAXLITLIQNI TA'MINLOVCHI VERTIKAL UMUMIY KABEL (HANDSHAKE UCHUN) ---
# Markaziy Handshake shinasidan o'ngga bitta chiziq chiqadi va u o'ngdagi ikkala qurilmani yaxlit bog'laydi
ax.plot([10.2, 11.0], [4.5, 4.5], color=COLOR_HANDSHAKE, lw=2.5, zorder=4) # Shina ichidan chiqish

# O'ng tomondagi ulanishlarni uzluksiz qiladigan vertikal yaxlit kabel tizimi (Talker va Listenerni ulaydi)
ax.plot([11.0, 11.0], [3.1, 5.9], color=COLOR_HANDSHAKE, lw=2.5, zorder=4)

# Ushbu vertikal umumiy kabeldan qurilmalarga kiruvchi gorizontal chiziqlar
ax.annotate('', xy=(11.0, 5.9), xytext=(11.7, 5.9), arrowprops=dict(arrowstyle="<->", color=COLOR_HANDSHAKE, lw=2.5, mutation_scale=14))
ax.annotate('', xy=(11.0, 3.1), xytext=(11.7, 3.1), arrowprops=dict(arrowstyle="<->", color=COLOR_HANDSHAKE, lw=2.5, mutation_scale=14))

# Umumiy ulanish (tarmoqlanish) nuqtasini ko'rsatuvchi marker
ax.plot([11.0], [4.5], marker='o', markersize=6, color='#212529', zorder=5)

plt.tight_layout()

# Tasvirni saqlash
plt.savefig('ieee_488_gpib_final_ideal.png', dpi=300, bbox_inches='tight')
plt.show()

