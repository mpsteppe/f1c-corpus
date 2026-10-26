int __thiscall sub_4040A0(float *this)
{
  int v2; // eax
  double v3; // st7
  char *v4; // eax
  int v5; // eax
  int v6; // edi
  int result; // eax
  double v8; // st7
  int v9; // [esp+4h] [ebp-4h]

  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_14, 2022) )
    sub_4D7AA0(&unk_8AD25C, aEnteredAidatab);
  v2 = 0;
  v9 = 0;
  do
  {
    if ( v2 )
      v3 = (double)v9;
    else
      v3 = 3.0;
    this[v2++ + 79] = v3;
    v9 = v2;
  }
  while ( v2 < 3 );
  this[76] = 0.0;
  this[77] = 0.0;
  this[78] = 0.0;
  this[71] = 0.5;
  this[72] = 1.0;
  this[73] = 1.3;
  *((_DWORD *)this + 88) = 104;
  *((_DWORD *)this + 89) = 52;
  *((_DWORD *)this + 90) = 3;
  *((_DWORD *)this + 87) = 1;
  *this = 4.75;
  this[1] = 4.3125;
  this[82] = -1.0;
  if ( sub_4C58A0(this + 6, 256, aAiDatabaseFile, 0) )
  {
    v4 = (char *)dword_7CE608;
    if ( !dword_7CE608 )
      v4 = &byte_5EA438;
    sub_587DD0(this + 6, v4, 200);
  }
  v5 = sub_587DB0(this + 6, aRt);
  v6 = v5;
  if ( v5 )
  {
    sub_402690((int)this, v5);
    sub_587D02(v6);
  }
  if ( dword_7D01A0 > 100 )
  {
    result = dword_7D01A0 - 100;
    v8 = (1.0 - (double)result * 0.050000001) * this[72] + (double)result * 0.050000001 * this[73];
  }
  else
  {
    result = dword_7D01A0 - 70;
    v8 = (1.0 - (double)result * 0.033333335) * this[71] + (double)result * 0.033333335 * this[72];
  }
  this[70] = v8;
  return result;
}
