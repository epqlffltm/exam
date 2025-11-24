import subprocess
from flask import Flask, render_template

state = 'off'
app = Flask(__name__)

def led_on_off(onoff):
    global state
    state = onoff
    subprocess.run(['sudo', '/home/pi/exam/led_control', onoff])

@app.route('/')
def index():
    return render_template('index.html', state=state)

@app.route('/led/<onoff>')
def led(onoff):
    led_on_off(onoff)
    print('led %s' % state)
    return render_template('index.html', state=onoff)

if __name__=='__main__':
    print('Webserver starts.')
    app.run(debug=True, port=5000, host='0.0.0.0')
    print('Webserver ends.')
