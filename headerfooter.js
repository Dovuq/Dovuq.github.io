function headerfooter ()
{
    var s=document.getElementById ("header");
    var fso=new ActiveXObject("Scripting.FileSystemObject");
    var ts=fso.OpenTextFile("/header.html", ForReading);
    var t="",tmp="";
    do
    {
        tmp=ts.ReadLine();
        t+=tmp;
    }
    while (tmp.length>0);
    s.innerHTML=t;
    s=document.getElementById ("footer");
    fso=new ActiveXObject("Scripting.FileSystemObject");
    ts=fso.OpenTextFile("/footer.html", ForReading);
    t=tmp="";
    do
    {
        tmp=ts.ReadLine();
        t+=tmp;
    }
    while (tmp.length>0);
    s.innerHTML=t;
}
