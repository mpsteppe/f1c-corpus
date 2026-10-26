int __thiscall sub_6CBC69(_DWORD *this)
{
  unsigned int v1; // kr00_4
  __int32 v2; // eax
  __int32 v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // edx
  int v7; // ebx
  _DWORD *v8; // ecx
  int v9; // edx
  int v10; // ecx
  unsigned __int8 v11; // cl
  int v12; // eax
  unsigned int v13; // edi
  int result; // eax
  int v15; // [esp-4h] [ebp-24h]
  __int32 v16; // [esp+0h] [ebp-20h] BYREF
  char *v17; // [esp+4h] [ebp-1Ch]
  int v18; // [esp+14h] [ebp-Ch] BYREF
  int v19; // [esp+18h] [ebp-8h] BYREF
  int v20; // [esp+1Ch] [ebp-4h] BYREF

  v4 = this[64];
  if ( (*((_BYTE *)this + 110) & 0x40) != 0 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    v6 = 0;
    if ( v5 )
    {
      v7 = this[5];
      v8 = *(_DWORD **)(v4 + 8);
      while ( *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v8) + 16) == v6 )
      {
        v5 = *(_DWORD *)(v4 + 4);
        ++v6;
        ++v8;
        if ( v6 >= v5 )
          goto LABEL_6;
      }
      v17 = "cannot clip from a swizzled vector";
      goto LABEL_26;
    }
LABEL_6:
    if ( v5 != 3 )
    {
      v17 = "clip must be performed from a float3 vector for ps_1_x models";
LABEL_26:
      v16 = v4;
      v1 = __readeflags();
      v2 = __ROL4__(dword_16C6F14, 255);
      __writeeflags(v1);
      v15 = *(_DWORD *)(_InterlockedExchange(&v16, v2) + 60);
      sub_686791((int)this, v15, v16, v17);
      return -2147467259;
    }
  }
  else if ( *(_DWORD *)(v4 + 4) != 4 )
  {
    v17 = "clip must be performed from a float4 vector for ps_2_0 models";
    goto LABEL_26;
  }
  v9 = *(_DWORD *)(this[5] + 4 * **(_DWORD **)(v4 + 8));
  v10 = *(_DWORD *)(v9 + 4);
  if ( v10 == this[32] )
  {
    if ( (*(int (__thiscall **)(_DWORD *, int, int *, int *))(*this + 136))(this, v9, &v19, &v20) < 0 )
    {
      sub_686791((int)this, 0, 4500, "internal error: unexpected input register type");
      return -2147467259;
    }
    v11 = v20;
    LOWORD(v12) = v19;
  }
  else
  {
    if ( v10 != this[34] )
    {
      v17 = "clip cannot be performed from a constant or literal";
      goto LABEL_26;
    }
    v11 = 0;
    v20 = 0;
    v12 = *(_DWORD *)(v9 + 12);
    v19 = v12;
  }
  v13 = v12 & 0x7FF | ((v11 & 0x18 | ((v11 | 0xFFFFFFF8) << 20)) << 8);
  result = sub_6CB0CE((int)this, 65);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *))(*this + 124))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)),
               &v18);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, unsigned int, int, int))(*this + 100))(this, v13, 983040, v18);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(_DWORD *))(*this + 96))(this);
        if ( result >= 0 )
        {
          result = sub_6C64E6(this);
          if ( result >= 0 )
            return 0;
        }
      }
    }
  }
  return result;
}
