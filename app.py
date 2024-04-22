from flask import Flask

app = Flask(__name__)

@app.route('/api/float_value', methods=['GET'])
def get_float_value():
    # Aqui você pode substituir este valor de exemplo por qualquer valor float que desejar
    float_value = 3.14
    return {'value': float_value}

if __name__ == '__main__':
    app.run(debug=True)
