JS代码：

var oSearchSuggest = function(searchFuc) {

// function oSearchSuggest(searchFuc) {

var searchsubmit = $('#btnSearchProject');

var input = $('#search');

var suggestWrap = $('#gov_search_suggest');

var key = "";

var init = function() {

input.bind('keyup', sendKeyWord);

input.bind('blur', function() { setTimeout(hideSuggest, 100); })

}

var hideSuggest = function() {

suggestWrap.hide();

}

//发送请求，根据关键字到后台查询

var sendKeyWord = function(event) {

//键盘选择下拉项

if (suggestWrap.css('display') == 'block' && event.keyCode == 38 || event.keyCode == 40) {

var current = suggestWrap.find('li.hover');

if (event.keyCode == 38) {

if (current.length > 0) {

var prevLi = current.removeClass('hover').prev();

if (prevLi.length > 0) {

prevLi.addClass('hover');

input.val(prevLi.html());

}

} else {

var last = suggestWrap.find('li:last');

last.addClass('hover');

input.val(last.html());

}

} else if (event.keyCode == 40) {

if (current.length > 0) {

var nextLi = current.removeClass('hover').next();

if (nextLi.length > 0) {

nextLi.addClass('hover');

input.val(nextLi.html());

}

} else {

var first = suggestWrap.find('li:first');

first.addClass('hover');

input.val(first.html());

}

}

//输入字符

} else {

var valText = $.trim(input.val());

if (valText == '' || valText == key) {

return;

}

searchFuc(valText);

key = valText;

}

}

//请求返回后，执行数据展示

this.dataDisplay = function(data) {

if (data.length <= 0) {

suggestWrap.hide();

return;

}

//往搜索框下拉建议显示栏中添加条目并显示

var li;

var tmpFrag = document.createDocumentFragment();

suggestWrap.find('ul').html('');

for (var i = 0; i < data.length; i++) {

li = document.createElement('LI');

li.innerHTML = data[i];

tmpFrag.appendChild(li);

}

suggestWrap.find('ul').append(tmpFrag);

suggestWrap.show();

//为下拉选项绑定鼠标事件,实现鼠标点击选取

suggestWrap.find('li').hover(function() {

suggestWrap.find('li').removeClass('hover');

$(this).addClass('hover');

}, function() {

$(this).removeClass('hover');

}).bind('mousedown', function() {

input.val(this.innerHTML);

suggestWrap.hide();

searchsubmit.click();

});

}

init();

};

//实例化输入提示的JS,参数为进行查询操作时要调用的函数名

var searchSuggest = new oSearchSuggest(sendKeyWordToBack);

//这是一个模似函数，实现向后台发送ajax查询请求，并返回一个查询结果数据，传递给前台的JS,再由前台JS来展示数据。本函数由程序员进行修改实现查询的请求

//参数为一个字符串，是搜索输入框中当前的内容

function sendKeyWordToBack(keyword) {

var sSearchKey = $("#search").val();

$("#search").bind("input propertychange", function(event) {

sSearchKey = $("#search").val();

});

$.ajax({

url: "WebService/wbsBLL.asmx/GetSearchInfo", //后台webservice里的方法名称根据自己需要实现返回数据位json

type: "POST",

dataType: "json",

async: false,

contentType: "application/json; charset=utf-8",

data: '{"sKeyName":"' + sSearchKey + '"}',

traditional: false,

beforeSend: function(x) { x.setRequestHeader("Content-Type", "application/json; charset=utf-8"); },

success: function(data) {

var aData = [];

for (var i in data) {

var jsonObj = $.parseJSON(data[i]);

for (var item in jsonObj) {

jsonObj = eval(jsonObj.SeachTable);

for (var i = 0; i < jsonObj.length; i++) {

if (jsonObj[i].projectName != "") {

aData.push(jsonObj[i].projectName);

}

}

}

}

searchSuggest.dataDisplay(aData);

},

error: function(msg, e) {

$("#filter_stationType").html("SQL语句有错误");

},

complete: function(x) {

}

});

}

index.css:

@charset "utf-8";

/* CSS Document */

body, ul, li {

margin: 0;

padding: 0;

}

body{

font-size:12px;

font-family:sumsun,arial;

color:#666666;

background:#FFFFFF;

}

#searchtable{background:#E4E9F2; border-bottom:1px solid #C8CFDA; padding:0px 8px;height: 33px;}

#searchtable label{font-size:14px; display:inline-block; float:left; color:#333; text-shadow:1px 1px 0px #EBF5FA; font-weight:bold; padding:10px 0 8px 16px; background:url(../images/pemIcons.png) 2px -34px no-repeat; _background:url(../images/pemIcons.gif) 2px -34px no-repeat;}

#searchtable #search{border: 1px solid #C3C3C3; border-top: 1px solid #7C7C7C; border-left: 1px solid #9A9A9A;background: url(../images/today.gif) 0 -162px white repeat-x;outline: none; padding:3px 4px; _padding:3px 4px 5px; display:inline-block; float:left; margin:6px 12px 4px 0; zoom:1;}

#searchtable .btnSubmit{margin-top:6px;margin-left:5px; zoom:1; border: 1px solid #236300; background: #6B9F40 url(../images/buttonbg01.png) repeat-x 0 0; font-size:12px; color:#FFF; line-height:24px; height:24px; width:60px; font-weight:bold; display:block; text-align:center; float:left;}

#searchtable .btnSubmit:hover{text-decoration:none; background-position:0 -32px;}

#searchtable .btnSubmit:active{background-position:0 -64px;}

#searchtable .fBtn:hover{color:#000;}

table.datagrid {

border:1px solid #DDDDDD;

border-collapse:collapse;

}

.gover_search{ position:relative; z-index:99; height:33px; padding:15px 0 0 20px; border:1px solid #b8cfe6; border-bottom:0; background:#E4E9F2;border-bottom:1px solid #C8CFDA;}

.gover_search_form{height:36px;}

.gover_search .search_t{ float:left; width:112px; line-height:26px; color:#666666;}

.gover_search .input_search_key{ float:left; width:462px; height:18px; padding:3px; margin-right:5px; border:1px solid #cccccc; line-height:18px; background:#FFFFFF;}

.gover_search .search_btn{ padding-left:4px; width:68px; height:26px; overflow:hidden; border:1px solid #cccccc; text-align:center; color:#ffffff; letter-spacing:5px; background: #6B9F40 url(../images/buttonbg01.png) repeat-x 0 0; cursor:pointer; font-weight:bold;}

.gover_search .search_suggest{ position:absolute; z-index:999; left:132px; top:41px; width:468px; border:1px solid #999999; display:none; }

.gover_search .search_suggest li{height:24px; overflow:hidden; padding-left:3px; line-height:24px; background:#FFFFFF; cursor:default;}

.gover_search .search_suggest li.hover{background:#DDDDDD;}