import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT, initial=GPIO.HIGH)
GPIO.setup(27, GPIO.OUT, initial=GPIO.HIGH)
GPIO.setup(23, GPIO.OUT, initial=GPIO.HIGH)
GPIO.setup(24, GPIO.OUT, initial=GPIO.HIGH)

GPIO.setup(16, GPIO.OUT, initial=GPIO.HIGH)
GPIO.setup(20, GPIO.OUT, initial=GPIO.HIGH)
GPIO.setup(21, GPIO.OUT, initial=GPIO.HIGH)
GPIO.setup(26, GPIO.OUT, initial=GPIO.HIGH)


def on(gpio_number):
  GPIO.output(gpio_number, GPIO.LOW)
  sleep(0.05)
  GPIO.output(gpio_number, GPIO.HIGH)

def key_select(input_key):
  if input_key == 'a':
    on(17)
  elif input_key == 'b':
    on(27)
  elif input_key == 'home':
    on(23)
  elif input_key == 'game':
    on(24)
  elif input_key == 'u':
    on(16)
  elif input_key == 'd':
    on(20)
  elif input_key == 'r':
    on(21)
  elif input_key == 'l':
    on(26)
  else:
    pass


if __name__ == '__main__':
  try:
    while True:
      print('push button')
      key = input()
      print(f'input is ${key}')
      key_select(key)

  except KeyboardInterrupt:
    GPIO.cleanup()
