int __thiscall sub_54B770(int this, int a2)
{
  int result; // eax
  int v4; // edx
  float v5[16]; // [esp+Ch] [ebp-80h] BYREF
  _BYTE v6[64]; // [esp+4Ch] [ebp-40h] BYREF

  result = *(_DWORD *)(this + 64);
  if ( result )
  {
    result = (*(int (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_8B8F24 + 8))(
               dword_8B8F24,
               this + 212,
               result + 276,
               this + 276);
  }
  else if ( (*(_BYTE *)(this + 60) & 1) != 0 )
  {
    qmemcpy((void *)(this + 276), (const void *)(this + 212), 0x40u);
  }
  v4 = *(_DWORD *)(this + 60);
  if ( (v4 & 0x4000) != 0 )
  {
    qmemcpy(v5, (const void *)(this + 212), sizeof(v5));
    v5[0] = v5[0] * *(float *)(this + 404);
    v5[1] = v5[1] * *(float *)(this + 404);
    result = *(_DWORD *)(this + 64);
    v5[2] = v5[2] * *(float *)(this + 404);
    v5[4] = v5[4] * *(float *)(this + 408);
    v5[5] = v5[5] * *(float *)(this + 408);
    v5[6] = v5[6] * *(float *)(this + 408);
    v5[8] = v5[8] * *(float *)(this + 412);
    v5[9] = v5[9] * *(float *)(this + 412);
    v5[10] = v5[10] * *(float *)(this + 412);
    if ( result )
    {
      if ( (v4 & 1) != 0 )
      {
        (*(void (__cdecl **)(int, float *, int, _BYTE *))(*(_DWORD *)dword_8B8F24 + 8))(
          dword_8B8F24,
          v5,
          this + 148,
          v6);
        return (*(int (__cdecl **)(int, _BYTE *, int, int))(*(_DWORD *)dword_8B8F24 + 8))(
                 dword_8B8F24,
                 v6,
                 *(_DWORD *)(this + 64) + 276,
                 this + 416);
      }
      else
      {
        return (*(int (__cdecl **)(int, float *, int, int))(*(_DWORD *)dword_8B8F24 + 8))(
                 dword_8B8F24,
                 v5,
                 result + 276,
                 this + 416);
      }
    }
    else if ( (v4 & 1) != 0 )
    {
      return (*(int (__cdecl **)(int, float *, int, int))(*(_DWORD *)dword_8B8F24 + 8))(
               dword_8B8F24,
               v5,
               this + 148,
               this + 416);
    }
    else
    {
      qmemcpy((void *)(this + 416), v5, 0x40u);
    }
  }
  else
  {
    qmemcpy((void *)(this + 416), (const void *)(this + 276), 0x40u);
  }
  return result;
}

