int __thiscall sub_436CF0(_DWORD *this, char *a2, char a3)
{
  int v3; // ebx

  v3 = 1;
  if ( !sub_4329D0((int)&byte_75CBC8, (char)a2, a2, 1) )
  {
    v3 = 0;
    if ( a3 )
    {
      sub_578600(a2);
      sub_4368C0(this, (int)a2, 0);
    }
  }
  return v3;
}
