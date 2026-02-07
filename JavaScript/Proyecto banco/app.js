const readline = require("readline/promises");
const Banco = require("./banco");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const banco = new Banco();

async function crearCuentaInicial() {
  while (banco.cuentas.length === 0) {
    console.log("No hay cuentas. Debes crear una.");

    const nombre = await rl.question("Nombre: ");
    const apellido = await rl.question("Apellido: ");
    const correo = await rl.question("Correo: ");

    if (!banco.crearCuenta(nombre, apellido, correo)) {
      console.log("Intenta nuevamente.\n");
    }
  }
}

async function menuPrincipal() {
  while (true) {
    console.log("\n----------BANCO en JS --------");

    let opcion = await rl.question(
      "Selecciona una opcion en número: \n1 - Crear cuenta\n2 - Ingresar \n3 - Cerrar programa \nOpción: "

    );

    if (opcion == 3) break;

    if (opcion == 1) {
      const nombre = await rl.question("Nombre: ");
      const apellido = await rl.question("Apellido: ");
      const correo = await rl.question("Correo: ");
      banco.crearCuenta(nombre, apellido, correo);
    }

    if (opcion == 2) {
      const correo = await rl.question("Correo: ");
      const cuenta = banco.buscarCuenta(correo);

      if (!cuenta) {
        console.log("La cuenta no existe.");
        continue;
      }

      await menuCuenta(cuenta);
    }
  }

  rl.close();
}

async function menuCuenta(cuenta) {
  while (true) {
    console.log(`\nBienvenido ${cuenta.nombre} ${cuenta.apellido}`);

    let accion = await rl.question(
      "Selecciona un número de opción \n1 - depositar \n2 - retirar \n3 - menu \n4 - Cerrar programa \nOpción: "
    );

    if (accion == 3) return;
    if (accion == 4) process.exit();

    const cantidad = parseFloat(
      await rl.question("Cantidad: ")
    );

    if (accion == 1)
      cuenta.depositar(cantidad);

    if (accion == 2)
      cuenta.retirar(cantidad);

    banco.guardarDatos();

    let volver = await rl.question(
      "¿Quieres volver al menú? escribe (si/no): "
    );

    if (volver !== "si") process.exit();
  }
}

async function main() {
  await crearCuentaInicial();
  await menuPrincipal();
}

main();
