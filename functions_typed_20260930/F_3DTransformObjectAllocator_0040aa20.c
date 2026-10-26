int __thiscall sub_40AA20(_DWORD *this)
{
  int result; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // esi
  _DWORD *v13; // ecx

  result = this[4];
  if ( !result )
  {
    v3 = OperatorNewNhMallocWrapper(200);
    if ( v3 )
      v4 = F_3DSoundEmitter(v3);
    else
      v4 = 0;
    this[4] = v4;
    result = v4 + 136;
    *(_DWORD *)result = 1135869952;
    *(_DWORD *)(result + 4) = 1135869952;
    *(_DWORD *)(result + 8) = 1135869952;
  }
  if ( !this[5] )
  {
    v5 = OperatorNewNhMallocWrapper(200);
    if ( v5 )
      v6 = F_3DSoundEmitter(v5);
    else
      v6 = 0;
    this[5] = v6;
    result = v6 + 136;
    *(_DWORD *)result = 1135869952;
    *(_DWORD *)(result + 4) = 1135869952;
    *(_DWORD *)(result + 8) = 1135869952;
  }
  if ( !this[6] )
  {
    v7 = OperatorNewNhMallocWrapper(200);
    if ( v7 )
      v8 = F_3DSoundEmitter(v7);
    else
      v8 = 0;
    this[6] = v8;
    result = v8 + 136;
    *(_DWORD *)result = 1135869952;
    *(_DWORD *)(result + 4) = 1135869952;
    *(_DWORD *)(result + 8) = 1135869952;
  }
  if ( !this[7] )
  {
    v9 = OperatorNewNhMallocWrapper(200);
    if ( v9 )
      v10 = F_3DSoundEmitter(v9);
    else
      v10 = 0;
    this[7] = v10;
    result = v10 + 136;
    *(_DWORD *)result = 1135869952;
    *(_DWORD *)(result + 4) = 1135869952;
    *(_DWORD *)(result + 8) = 1135869952;
  }
  if ( !this[8] )
  {
    v11 = (_DWORD *)OperatorNewNhMallocWrapper(204);
    if ( v11 )
    {
      v12 = v11 + 1;
      *v11 = 1;
      F_3DSoundEmitter(v11 + 1);
    }
    else
    {
      v12 = 0;
    }
    this[8] = v12;
    StringCopyWithBufferRealloc(&byte_5EA438);
    v12[3] = 0;
    v12[4] = 0;
    v12[5] = 0;
    v12[6] = 0;
    v12[7] = 0;
    v12[8] = 0;
    v12[9] = 0;
    v12[10] = 0;
    v12[11] = 0;
    v12[14] = 1114636288;
    v12[12] = 1114636288;
    v12[15] = 1110704128;
    v12[13] = 1110704128;
    v12[16] = 1056964608;
    v12[17] = 1140457472;
    v12[18] = 1065353216;
    v12[20] = 1065353216;
    v12[19] = 1065353216;
    v12[22] = 1056964608;
    v12[21] = 1056964608;
    v12[23] = 0;
    v12[27] = 0;
    v12[26] = 0;
    v12[25] = 0;
    v12[30] = 0;
    v12[29] = 0;
    v12[28] = 0;
    *((_BYTE *)v12 + 96) = 0;
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)this[8] + 28))(this[8]);
    result = 1135869952;
    v13 = (_DWORD *)(this[8] + 136);
    *v13 = 1135869952;
    v13[1] = 1135869952;
    v13[2] = 1135869952;
  }
  return result;
}

