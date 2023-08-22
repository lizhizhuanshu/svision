from PIL import Image
import os

def get_rgb(image_path, x, y):
    # 打开图片
    img = Image.open(image_path)
    
    # 确保图片是RGB模式
    if img.mode != "RGB":
        img = img.convert("RGB")
    
    # 获取指定坐标的颜色
    r, g, b = img.getpixel((x, y))
    
    return r, g, b

if __name__ == "__main__":

    # 获取当前脚本的绝对路径
    script_path = os.path.abspath(__file__)

    # 获取当前脚本的目录
    script_dir = os.path.dirname(script_path)

    image_path = script_dir + os.sep+ "test.png"
    print(str.format("{:02x}{:02x}{:02x}", *get_rgb(image_path, 156,176)))
