char __thiscall sub_4B0960(char *this, int a2, int a3, int a4)
{
  int v5; // ebp
  int v6; // ebx
  char *v7; // eax
  bool v8; // zf
  _DWORD *v9; // edi
  double v10; // st7
  double v11; // st7
  char result; // al
  int v13; // [esp+10h] [ebp-4h] BYREF

  sub_4B0930((int)this, 1);
  sub_578600(a2);
  v5 = a3;
  v6 = a4;
  a2 = a3;
  v13 = a4;
  sub_4B0900(&a2);
  sub_4B0900(&v13);
  v7 = *(char **)this;
  v8 = *(_DWORD *)this == 0;
  *((_DWORD *)this + 8) = 8;
  if ( v8 )
    v7 = &byte_629120;
  v9 = this + 8;
  if ( sub_5A29F0((int)(this + 8), v7, a2, v13, 8, 0, 4, 1) || !*(_DWORD *)(*v9 + 16) )
  {
    if ( *v9 )
    {
      sub_5A2B00(*v9);
      *v9 = 0;
    }
    return 0;
  }
  else
  {
    v10 = (double)a3;
    *((_DWORD *)this + 5) = v5;
    *((_DWORD *)this + 6) = v6;
    v11 = v10 / (double)a2;
    this[36] = 1;
    result = 1;
    *((float *)this + 3) = v11;
    *((float *)this + 4) = (double)a4 / (double)v13;
  }
  return result;
}
