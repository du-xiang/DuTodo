// 创建 XMLHttpRequest 对象
var xhr = new XMLHttpRequest();

// 指定要获取的 JSON 文件的 URL
var url = 'Info/memo.json';

// 监听请求状态变化事件
xhr.onreadystatechange = function() {
  if (xhr.readyState === 4 && xhr.status === 200) {
    // 请求完成并成功获取 JSON 文件
    var jsonData = JSON.parse(xhr.responseText);
    // 将内容打印在网页中
    var memo = document.getElementById("info_memo");
    outputJson(memo, jsonData);
  }
};

// 发送 GET 请求以获取 JSON 文件
xhr.open('GET', url, true);
xhr.send();


// 将文本内容打印在网页中
function outputJson(contain, json){
    // 拼接表格内容
    var tableStr = "<table>\n";
    for(var i = 0; i < json.length; i++){
        tableStr += "<tr>\n";
        tableStr += "\t<td>" + json[i].addTime + "</td>\n";
        tableStr += "\t<td>" + json[i].content + "</td>\n";
        tableStr += "</tr>\n";
    }
    tableStr += "</table>";
    //将拼接的字符串放进容器里
    contain.innerHTML = tableStr;
}