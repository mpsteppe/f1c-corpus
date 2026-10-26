char __thiscall sub_4E3680(char *this, int a2, int a3, int a4)
{
  void *v5; // eax
  void **v6; // edi
  int v7; // edx
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  const CHAR *v11; // ecx
  bool v12; // zf
  char result; // al
  int v14; // [esp+10h] [ebp-4h]
  int v15; // [esp+18h] [ebp+4h]

  v5 = (void *)*((_DWORD *)this + 2);
  v6 = (void **)(this + 8);
  if ( v5 )
  {
    sub_5E4BF0(dword_FB1CE0, v5);
    *v6 = 0;
  }
  sub_615860(a2);
  v7 = 1;
  v8 = 0;
  v15 = 1;
  if ( a3 > 1 )
  {
    do
    {
      v7 = 1 << ++v8;
      v15 = 1 << v8;
    }
    while ( a3 > 1 << v8 );
  }
  v9 = 1;
  v10 = 0;
  v14 = 1;
  if ( a4 > 1 )
  {
    do
    {
      v9 = 1 << ++v10;
      v14 = 1 << v10;
    }
    while ( a4 > 1 << v10 );
  }
  v11 = *(const CHAR **)this;
  v12 = *(_DWORD *)this == 0;
  *((_DWORD *)this + 8) = 8;
  if ( v12 )
    v11 = WindowName;
  if ( sub_5E47E0(dword_FB1CE0, (int)v6, (char)v11, v7, v9, 8, 0, 4, 1) || !*v6 )
  {
    if ( *v6 )
    {
      sub_5E4BF0(dword_FB1CE0, *v6);
      *v6 = 0;
    }
    return 0;
  }
  else
  {
    *((_DWORD *)this + 5) = a3;
    *((_DWORD *)this + 6) = a4;
    this[36] = 1;
    result = 1;
    *((float *)this + 3) = (double)a3 / (double)v15;
    *((float *)this + 4) = (double)a4 / (double)v14;
  }
  return result;
}
