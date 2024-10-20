document.getElementById('login-form').addEventListener('submit', function(event) {
    event.preventDefault();
    var username = document.getElementById('username').value;
    var password = document.getElementById('password').value;
    // You can add your login validation logic here
    // For example, you can send a request to a server for authentication
    console.log('Username:', username);
    console.log('Password:', password);
});
