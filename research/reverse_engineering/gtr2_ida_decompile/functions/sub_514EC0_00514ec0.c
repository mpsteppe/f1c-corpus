int __thiscall sub_514EC0(char *this, char *a2, int a3)
{
  char *v3; // esi
  char *v4; // eax
  int v5; // edx
  char v6; // cl
  const CHAR *v7; // edx

  v3 = this + 20;
  v4 = a2;
  v5 = this + 20 - a2;
  do
  {
    v6 = *v4;
    v4[v5] = *v4;
    ++v4;
  }
  while ( v6 );
  v7 = dword_91CB00;
  if ( !dword_91CB00 )
    v7 = WindowName;
  if ( !sub_616480(v3, v7) )
    sub_501AC0();
  return sub_510480();
}
