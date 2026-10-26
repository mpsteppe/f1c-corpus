int __thiscall sub_45DE70(_DWORD *this, float *a2, float a3)
{
  float *v3; // ebx
  unsigned int v4; // esi
  double v6; // st7
  unsigned __int8 v7; // al
  double v8; // st7
  double v9; // st7
  int result; // eax
  float v11; // [esp+0h] [ebp-18h]
  int v12; // [esp+14h] [ebp-4h]

  v3 = a2;
  v4 = *(_DWORD *)a2 & 0x3F;
  v12 = ((*(_DWORD *)a2 >> 6) & 0x3FF) + 8;
  if ( v4 < 0x31 )
  {
    v6 = *(float *)&this[v4 + 54];
    this[v4 + 5] = 0;
    if ( v6 > 0.5 )
    {
      this[v4 + 520] = -1082130432;
      v11 = a3 - v3[1];
      sub_45DD20(v11, (_WORD *)&this[8 * v4 + 127] + *((unsigned __int8 *)this + v4 + 461) + 1);
      v7 = *((_BYTE *)this + v4 + 412);
      if ( v7 < 0x10u )
        *((_BYTE *)this + v4 + 412) = v7 + 1;
      *((_BYTE *)this + v4 + 461) = (*((_BYTE *)this + v4 + 461) + 1) & 0xF;
      this[v4 + 54] = 0;
    }
    if ( (unsigned __int8)sub_45E160(v4, &a2) )
      v3[1] = v3[1] - *(float *)&a2;
    v8 = sub_527940(&unk_7DA938);
    if ( v3[1] <= v8 )
    {
      v9 = v8 - flt_769A90;
      if ( v3[1] < v9 )
        v3[1] = v9;
    }
    else
    {
      v3[1] = v8;
    }
  }
  result = this[2] + 1;
  this[1] += v12;
  this[2] = result;
  return result;
}
