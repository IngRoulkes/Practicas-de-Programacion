import csv

def leer_contactos(archivo_csv):
    contactos = []
    with open(archivo_csv, newline='', encoding='utf-8') as csvfile:
        lector = csv.DictReader(csvfile)
        for fila in lector:
            contactos.append(fila)
    return contactos

def eliminar_duplicados(contactos):
    vistos = set()
    contactos_unicos = []
    duplicados = []
    
    for contacto in contactos:
        email = contacto['Email']
        if email not in vistos:
            contactos_unicos.append(contacto)
            vistos.add(email)
        else:
            duplicados.append(contacto) 
    
    if duplicados:
        print("\nSe eliminaron los siguientes contactos duplicados:")
        for dup in duplicados:
            print(f"- Nombre: {dup['Nombre']}, Email: {dup['Email']}, Teléfono: {dup['Teléfono']}")
        print(f"Total de duplicados eliminados: {len(duplicados)}\n")
    else:
        print("\nNo se encontraron duplicados.\n")
    
    return contactos_unicos

def ordenar_contactos(contactos):
    return sorted(contactos, key=lambda x: x['Nombre'])

def guardar_contactos(contactos, archivo_salida):
    campos = ['Nombre', 'Email', 'Teléfono']
    with open(archivo_salida, 'w', newline='', encoding='utf-8') as csvfile:
        escritor = csv.DictWriter(csvfile, fieldnames=campos)
        escritor.writeheader()
        escritor.writerows(contactos)
print("<--------------------------------------------------------------->")

def mostrar_contactos_numerados(contactos):
    print("Contactos finales ya organizados:")
    for i, contacto in enumerate(contactos, start=1):
        print(f"{i}.- Nombre: {contacto['Nombre']}, Email: {contacto['Email']}, Teléfono: {contacto['Teléfono']}")

archivo_entrada = 'contactos.csv'
archivo_salida = 'contactos_organizados.csv'
contactos = leer_contactos(archivo_entrada)
contactos = eliminar_duplicados(contactos)
contactos = ordenar_contactos(contactos)
print("<--------------------------------------------------------------->")
guardar_contactos(contactos, archivo_salida)
mostrar_contactos_numerados(contactos)
print("<--------------------------------------------------------------->")