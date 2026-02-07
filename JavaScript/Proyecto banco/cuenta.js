class Cuenta {
  constructor(nombre, apellido, correo, saldo = 0) {
    this.nombre = nombre;
    this.apellido = apellido;
    this.correo = correo;
    this.saldo = saldo;
  }

  depositar(cantidad) {
    console.log(`Este es tu saldo inicial: $${this.saldo}`);
    this.saldo += cantidad;
    console.log(`Este es tu saldo final: $${this.saldo}`);
  }

  retirar(cantidad) {
    console.log(`Este es tu saldo inicial: $${this.saldo}`);
    if (cantidad > this.saldo) {
      console.log("Tienes fondos insuficientes");
      return;
    }
    this.saldo -= cantidad;
    console.log(`Este es tu saldo final: $${this.saldo}`);
  }
}

module.exports = Cuenta;
