const char indexpage[] PROGMEM = R""""(
<html>
<head>
<meta charset='UTF-8'>
<meta http-equiv='refresh' content='60'>
<link rel="icon" href="data:,">
<script src='https://cdn.plot.ly/plotly-2.8.3.min.js'></script>
<script src='https://d3js.org/d3.v4.min.js'></script>
</head>
<body>
<div id='plotarea'></div>
<script>
const now = Date.now();
const plotarea = document.getElementById('plotarea');

d3.csv('data.csv', function(err, rows){
function unpack(rows, key) {
	return rows.map(row =>row[key]);
}
function actualtime(values){
	return values.map(t => new Date((t*1000)+now));
}

let times = actualtime(unpack(rows, 'time'));

for (let i in rows.columns.slice(1)){
	const key = rows.columns[+i+1];
	let trace1 = {
		type: 'scatter',
		mode: 'lines',
		name: key,
		x: times,
		y: unpack(rows,key)
	};

	let new_plot_div = document.createElement('div');
	new_plot_div.id = 'plot_' + key;
	plotarea.appendChild(new_plot_div);
	Plotly.newPlot(new_plot_div.id, [trace1], {title: 'ANAVI '+key});
}
})
</script>
</body>
</html>
)"""";
