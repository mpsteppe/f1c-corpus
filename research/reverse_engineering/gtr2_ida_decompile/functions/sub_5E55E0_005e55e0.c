void __thiscall sub_5E55E0(_DWORD *this, int a2)
{
  float v2; // [esp+0h] [ebp-Ch]
  float v3; // [esp+4h] [ebp-8h]

  if ( a2 )
  {
    this[192] = a2;
    v3 = (float)*(int *)(a2 + 8);
    v2 = (float)*(int *)(a2 + 4);
    sub_5E53E0((int)this, 0.0, 0.0, v2, v3, 0);
  }
}
