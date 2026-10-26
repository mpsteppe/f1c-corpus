// Address: 0x00406659
// Size: 88 bytes
// Name: sub_406659
// Type: int __userpurge@<eax>(int@<esi>, float)
// Source: IDA Hex-Rays decompilation

int __userpurge sub_406659@<eax>(int a1@<esi>, float a2)
{
  float *v2; // ecx
  float *v3; // esi
  int v4; // edx
  int result; // eax
  int v6; // ecx
  _UNKNOWN *retaddr; // [esp+14h] [ebp+0h]

  sub_405013();
  v3 = v2;
  v4 = *(_DWORD *)v2;
  *((_DWORD *)v2 + 1) = retaddr;
  result = (*(int (__stdcall **)(int))(v4 + 8))(a1);
  if ( result )
  {
    v6 = *((_DWORD *)v3 + 3);
    if ( v6 )
    {
      if ( a2 == 0.0 )
        return (*(int (__thiscall **)(float *))(*(_DWORD *)v3 + 12))(v3);
      else
        return ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))AIL_set_stream_volume_levels)(v6, v3[1], v3[1]);
    }
  }
  return result;
}
