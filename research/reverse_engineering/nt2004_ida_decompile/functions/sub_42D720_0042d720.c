double __thiscall sub_42D720(int this, int a2)
{
  float v5; // [esp+8h] [ebp+4h]

  if ( *(float *)(this + 24712) <= 0.0 )
    return sub_42B090(this, *(_DWORD *)(this + 24020), 0);
  v5 = sub_42B090(this, *(_DWORD *)(this + 24708), a2);
  return sub_42B090(this, *(_DWORD *)(this + 24020), a2) * (1.0 - *(float *)(this + 24712))
       + v5 * *(float *)(this + 24712);
}
