const pagenum=2;
var page=1;
function load ()
{
    var s,t="";
    for (var i=1;i<=pagenum;i++)
    {
        s=document.getElementById("page"+i);
        if (i==page)
        {
            s.style.display="";
            t+="<button onclick=turn("+i+")>"+i+"</button>\n";
        }
        else
        {
            s.style.display="none";
            t+=i+"\n";
        }
    }
    s=document.getElementById("set_page");
    s.innerHTML=t;
    s=document.getElementById("prev_page");
    if (page==1) s.hidden="1";
    else s.hidden="";
    s=document.getElementById("next_page");
    if (page==pagenum) s.hidden="1";
    else s.hidden="";
}
function turntopage (p)
{
    page=p;
    load ();
}
window.onload=load ();
