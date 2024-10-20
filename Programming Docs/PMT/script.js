function calculateAge() {
    var dob = document.getElementById('dob').value;
    var dobDate = new Date(dob);
    var todayDate = new Date();
    var age = todayDate.getFullYear() - dobDate.getFullYear();
    var monthDiff = todayDate.getMonth() - dobDate.getMonth();
  
    if (monthDiff < 0 || (monthDiff === 0 && todayDate.getDate() < dobDate.getDate())) {
      age--;
    }
  
    document.getElementById('result').innerText = 'Your age is: ' + age;
  }
  