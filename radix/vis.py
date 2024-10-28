import warnings
warnings.filterwarnings("ignore", category=UserWarning)

import os
import subprocess
import matplotlib.pyplot as plt
import glob
import numpy as np

def parse_array_state(file_content):
    # Преобразуем содержимое файла в список чисел, если оно записано построчно
    return [int(line) for line in file_content.strip().splitlines()]

def generate_frames(files_pattern="step_*.txt", output_dir="frames"):
    os.makedirs(output_dir, exist_ok=True)
    
    # Получаем список файлов, сортируем их по номеру
    files = sorted(glob.glob(files_pattern), key=lambda x: int(x.split('_')[1].split('.')[0]))
    
    for i, file_path in enumerate(files):
        with open(file_path, "r") as file:
            file_content = file.read()
            array_state = parse_array_state(file_content)
            
            # Настройка графика с улучшениями
            plt.figure(figsize=(10, 6))
            
            # Применяем стиль
            plt.style.use('ggplot')  # Используем стиль ggplot
            
            # Генерация цветов с градиентом
            colors = plt.cm.viridis(np.linspace(0, 1, len(array_state)))

            # Построение графика
            bars = plt.bar(range(len(array_state)), array_state, color=colors, edgecolor="black", linewidth=1.5)
            
            # Добавляем подписи значений на столбцах
            for bar in bars:
                yval = bar.get_height()
                plt.text(bar.get_x() + bar.get_width()/2, yval + 0.5, int(yval), ha='center', va='bottom', fontsize=10, fontweight='bold', color='black')
            
            # Настройка заголовка и меток
            plt.title(f"Step {i+1}", fontsize=16, fontweight='bold', color='#333333')
            plt.xlabel("Index", fontsize=14, fontweight='bold')
            plt.ylabel("Value", fontsize=14, fontweight='bold')
            
            # Настройка осей
            plt.xticks(fontsize=12)
            plt.yticks(fontsize=12)
            
            # Добавляем сетку
            plt.grid(True, which='major', linestyle='--', linewidth=0.7, alpha=0.7)
            
            # Сохранение кадра
            plt.savefig(f"{output_dir}/frame_{i+1:03d}.png", bbox_inches='tight', dpi=150)
            plt.close()

def generate_video(frames_dir="frames", output_file="sorting_visualization.mp4"):
    # Создаем видео из сгенерированных кадров с помощью ffmpeg
    subprocess.run([
        "ffmpeg", "-framerate", "5", "-i", f"{frames_dir}/frame_%03d.png",
        "-c:v", "libx264", "-pix_fmt", "yuv420p", output_file
    ])

# Запуск всех этапов
generate_frames()   # Генерация кадров из файлов step_{номер}.txt
generate_video()    # Создание видео из сгенерированных кадров
