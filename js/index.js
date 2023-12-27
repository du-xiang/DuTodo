function loadData() {
    fetch('http://localhost/cgi-bin/backend.cgi')
        .then(response => response.text())  // 获取原始文本数据
        .then(data => {
            document.getElementById('backendResponse').innerText = data;
            console.log(data);  // 输出原始数据
            console.log(JSON.parse(data));  // 尝试解析 JSON
        })
        .catch(error => {
            console.error('Error:', error);
       });
}

// 网页开始时加载数据
loadData()