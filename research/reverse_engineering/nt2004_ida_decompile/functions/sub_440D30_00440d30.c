int __thiscall sub_440D30(_DWORD *this)
{
  int result; // eax
  float v3; // [esp+18h] [ebp-18h] BYREF
  float v4; // [esp+1Ch] [ebp-14h] BYREF
  float v5; // [esp+20h] [ebp-10h] BYREF
  float v6; // [esp+24h] [ebp-Ch] BYREF
  float v7; // [esp+28h] [ebp-8h] BYREF
  float v8; // [esp+2Ch] [ebp-4h] BYREF

  result = 1072693248;
  this[2169] = 0;
  this[2170] = 1072693248;
  this[2171] = 0;
  this[2172] = 1072693248;
  this[2173] = 0;
  this[2174] = 1072693248;
  this[2175] = 0;
  this[2176] = 1072693248;
  this[2177] = 0;
  this[2178] = 1072693248;
  this[2179] = 0;
  this[2180] = 1072693248;
  if ( *(_DWORD *)dword_7689CC == 8 )
  {
    if ( dword_76BB24 )
    {
      result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
      if ( result )
      {
        result = (*(int (__thiscall **)(_DWORD, float *, float *, float *, float *, float *, float *))(**(_DWORD **)(result + 28) + 180))(
                   *(_DWORD *)(result + 28),
                   &v3,
                   &v4,
                   &v5,
                   &v6,
                   &v7,
                   &v8);
        if ( (_BYTE)result )
        {
          *(double *)(this + 2169) = v3;
          *(double *)(this + 2171) = v4;
          *(double *)(this + 2173) = v5;
          *(double *)(this + 2175) = v6;
          *(double *)(this + 2177) = v7;
          *(double *)(this + 2179) = v8;
        }
      }
    }
  }
  return result;
}
