from flask import Flask

app = Flask(__name__)

@app.route('/api/distancia_limite', methods=['GET'])

def get_distancia_limite():
    # Valor distancia a subtituir quando necessário
    distancia_limite = 3.14
    return {'value': distancia_limite}

if __name__ == '__main__':
    app.run(debug=True)
    # ACESSE http://localhost:5000/api/distancia_limite para coletar o valor
