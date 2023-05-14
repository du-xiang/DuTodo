// 创建 XMLHttpRequest 对象
var xhr = new XMLHttpRequest();

// 指定要获取的 JSON 文件的 URL
var url = 'memo.json';

// 监听请求状态变化事件
xhr.onreadystatechange = function() {
  if (xhr.readyState === 4 && xhr.status === 200) {
    // 请求完成并成功获取 JSON 文件
    var jsonData = JSON.parse(xhr.responseText);
    // 在这里可以使用 jsonData 对象进行进一步操作
    console.log(jsonData);
  }
};

// 发送 GET 请求以获取 JSON 文件
xhr.open('GET', url, true);
xhr.send();