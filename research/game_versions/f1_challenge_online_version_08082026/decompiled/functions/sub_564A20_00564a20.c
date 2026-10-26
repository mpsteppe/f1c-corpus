int __thiscall sub_564A20(int *this, int a2, int a3, int a4)
{
  int v5; // eax
  int v6; // eax
  int v8; // [esp-10h] [ebp-1Ch]
  int v9; // [esp-Ch] [ebp-18h]
  int v10; // [esp-Ch] [ebp-18h]
  int v11; // [esp-8h] [ebp-14h]
  int v12; // [esp+8h] [ebp-4h] BYREF

  v12 = 1;
  if ( !this )
    return -1;
  v5 = *this;
  if ( !*this )
    return -1;
  if ( a4 )
  {
    v9 = this[2];
    v8 = v5 - a3;
    sub_5648B0((int)this, a3);
    v6 = sub_564B10(v8, v9, a2, &v12);
  }
  else
  {
    v11 = this[2];
    v10 = v5 - a3;
    sub_5648B0((int)this, a3);
    v6 = sub_564AB0(v10, v11, a2);
  }
  if ( v6 && v12 )
    return (v6 - this[5]) / this[2];
  else
    return -1;
}
