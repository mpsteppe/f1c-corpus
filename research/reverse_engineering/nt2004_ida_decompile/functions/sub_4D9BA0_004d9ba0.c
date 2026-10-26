char __thiscall sub_4D9BA0(float **this, int a2, int a3, float a4)
{
  char **v4; // edx
  float *v5; // eax
  float *v6; // edi
  int v7; // ebp
  char v8; // al
  char v9; // bl

  v4 = (char **)this;
  if ( a4 == -9.9999997e37 )
    a4 = sub_4D83C0(*this);
  v5 = sub_4D6DB0(*v4, a2, a4);
  v6 = v5;
  if ( !v5 )
    return 0;
  if ( !(unsigned __int8)sub_52E830(v5 + 37) || (unsigned __int8)sub_52E850(v6 + 37) )
  {
    if ( (unsigned __int8)sub_52E830(v6 + 37) || !(unsigned __int8)sub_52E850(v6 + 37) )
    {
      v7 = a3;
      v8 = sub_52E870(a4, a3, *((float *)&unk_6310C4 + 6326 * a2));
    }
    else
    {
      v7 = a3;
      v8 = sub_52E720(a4, (int)(v6 + 39), a3);
    }
  }
  else
  {
    v7 = a3;
    v8 = sub_52E720(a4, (int)(v6 + 91), a3);
  }
  v9 = v8;
  sub_4EEC50(*(_BYTE *)(v7 + 15) & 1);
  return v9;
}
