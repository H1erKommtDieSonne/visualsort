import warnings
warnings.filterwarnings("ignore", category=UserWarning)

import numpy as np
import os
import matplotlib.pyplot as plt
import seaborn as sns
import glob

sns.set_style('darkgrid')  # устанавливаем стиль Seaborn

def parse_array_state(file_content):
    return [int(line) for line in file_content.strip().splitlines()]

def generate_frames(files_pattern="step_*.txt", output_dir="frames"):
    os.makedirs(output_dir, exist_ok=True)
    
    files = sorted(glob.glob(files_pattern), key=lambda x: int(x.split('_')[1].split('.')[0]))
    
    for i, file_path in enumerate(files):
        with open(file_path, "r") as file:
            file_content = file.read()
            array_state = parse_array_state(file_content)
            
            plt.figure(figsize=(10, 6))
            
            colors = plt.cm.viridis(np.linspace(0, 1, len(array_state)))
            bars = plt.bar(range(len(array_state)), array_state, color=colors, edgecolor="black", linewidth=1.5)
            
            for bar in bars:
                yval = bar.get_height()
                plt.text(bar.get_x() + bar.get_width()/2, yval + 0.5, int(yval), ha='center', va='bottom', fontsize=10, fontweight='bold', color='black')
            
            plt.title(f"Step {i+1}", fontsize=16, fontweight='bold', color='#333333')
            plt.xlabel("Index", fontsize=14, fontweight='bold')
            plt.ylabel("Value", fontsize=14, fontweight='bold')
            plt.xticks(fontsize=12)
            plt.yticks(fontsize=12)
            plt.grid(True, which='major', linestyle='--', linewidth=0.7, alpha=0.7)
            
            plt.savefig(f"{output_dir}/frame_{i+1:03d}.png", bbox_inches='tight', dpi=150)
            plt.close()
generate_frames()
