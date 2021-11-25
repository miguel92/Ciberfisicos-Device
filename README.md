# Ciberfisicos-Device

<p>Proyecto de la Univerisdad de Málaga para la asignatura SEGURIDAD EN SISTEMAS INDUSTRIALES Y CIBERFÍSICOS realizado por:</p>

<ul>
  <li>Miguel Alejandro martín Gómez</li>
  <li>Otman Zitan</li>
  <li>Rafael Alejandro García Rodríguez</li>
</ul>

<p>En este proyecto se realiza la conexión de una ESP-32 que hace el papel de cliente, con un servidor de Python para solicitar un JWT firmado y luego la ESP utilzia este JWT como método de autenticación para conectarse a un MQTT y enviar unos valores que se mostrarán en un dashboard crado en Node-Red.</p>

<p>En el proyecto podemos encontrarnos cinco carpetas</p>

<ul>
  <li><b>NodeRed UI:</b> En ella se guarda el código del dashboard.</li>
  <li><b>ciberfisicos_TLS:</b> En ella se guarda el código de la ESP-32.</li>
  <li><b>server_jwt:</b> En ella se guarda el código del servidor que proporciona el JWT firmado y los certificados necesarios para aplicar el TLS en esta comunicación.</b></li>
  <li><b>Ficheros conf:</b> Incluye los archivos de configuración del EMQX que tenemos configurados nosotros para el correcto funcionamiento.</b></li>
  <li><b>Certs emqx:</b> Certificados usados para aplicar TLS en la co,unicación MQTT.</b></li>
</ul>

<p>Para ejecutar el Node-Red simplemente debemos de instalarlo e importar el archivo que hay dentro de la carpeta y se crea todo el dashboard automáticamente.</p>
<p>El código de la ESP-32 simplemente descargarlo, compilarlo y cargarlo.</p>
<p>Finalmente, para ejecutar el servidor solamente tenemos que poner el comando "python3.9 server_tls.py" y se ejecutará.</p>
