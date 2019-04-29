var socket = io()

function dupa(){
	console.log("dzia³a");
	//alert('Hello world!');
	console.log(this.id);
}

function connect() {
        socket.emit('my_event', {data: 'I\'m connected!'});
}

function sendMsg() {
	console.log("sending a message")
	socket.emit('myMsg', {data: 'I clicked a button'});
}

document.getElementById("pierwszy").style.width = "300px";
document.getElementById("pierwszy").addEventListener("click", 
	function(){
  		document.getElementById("pierwszy").innerHTML = "Hello World"
	}
);

/*$("#pierwszy").click(function(){
  $(this).hide();
});*/

$("#pierwszy").click(dupa);

//socket.on('resp', function () { console.log("Connected!");});
socket.on('resp', function (data) { console.log(data);});