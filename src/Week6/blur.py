# PIL = Pillow library
from PIL import Image, ImageFilter

before = Image.open("stadium.bmp")
after = before.filter(ImageFilter.BLUR)
after.save("out.bmp")