const fs = require("fs");
const Cuenta = require("./cuenta");

const DB = "cuentas.json";

class Banco {
  constructor() {
    this.cuentas = this.cargarDatos();
  }

  validarCorreo(correo) {
    return correo.includes("@gmail.com" || "@hotmail.com" );
  }

  crearCuenta(nombre, apellido, correo) {
    if (!this.validarCorreo(correo)) {
      console.log("Correo inválido, debe tener terminación '@gmail.com' o '@hotmail.com' ");
      return false;
    }

    const cuenta = new Cuenta(nombre, apellido, correo);
    this.cuentas.push(cuenta);
    this.guardarDatos();
    console.log("Cuenta creada con exito");
    return true;
  }

  buscarCuenta(correo) {
    return this.cuentas.find(c => c.correo === correo);
  }

  guardarDatos() {
    fs.writeFileSync(DB, JSON.stringify(this.cuentas, null, 2));
  }

  cargarDatos() {
    if (!fs.existsSync(DB)) return [];

    const datos = JSON.parse(fs.readFileSync(DB));

    return datos.map(
      c => new Cuenta(c.nombre, c.apellido, c.correo, c.saldo)
    );
  }
}

module.exports = Banco;
