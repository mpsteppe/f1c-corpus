int __thiscall sub_563AC0(void *this)
{
  float v2; // ecx
  int *v3; // ecx
  int v4; // eax
  int *v5; // esi
  int v6; // eax
  int *v7; // esi
  char v8; // cl
  char v9; // cl
  unsigned __int8 v10; // al
  int *v11; // esi
  int *v12; // esi
  int *v13; // esi
  int *v14; // edi
  int v16; // [esp+4h] [ebp-4h] BYREF

  v2 = *(float *)this;
  if ( v2 != NAN && flt_757718 <= 0.0 )
  {
    if ( *((float *)this + 62) > 0.0 )
    {
      *((float *)this + 62) = *((float *)this + 62) - dbl_FB1D10;
      goto LABEL_9;
    }
    v3 = (int *)*((_DWORD *)this + LODWORD(v2) + 6);
    if ( v3 )
    {
      if ( sub_563A90(v3) != 1 )
        goto LABEL_9;
      *((_DWORD *)this + 62) = 1056964608;
    }
    *(_DWORD *)this = -1;
  }
LABEL_9:
  v4 = *((_DWORD *)this + 1);
  if ( v4 != -1 )
  {
    v5 = (int *)*((_DWORD *)this + v4 + 31);
    if ( (*(unsigned __int8 (__thiscall **)(int *))(*v5 + 24))(v5) )
      sub_562E30((float *)&dword_FAE988, v5[1]);
    if ( *((_BYTE *)v5 + 8) )
      sub_5638A0((float *)v5);
    if ( (*(int (__thiscall **)(int *))(*v5 + 4))(v5) == 1 )
      *((_DWORD *)this + 1) = -1;
  }
  v6 = *((_DWORD *)this + 2);
  if ( v6 )
  {
    v7 = (int *)*((_DWORD *)this + v6 + 3);
    if ( (*(unsigned __int8 (__thiscall **)(int *))(*v7 + 24))(v7) )
      sub_562E30((float *)&dword_FAE988, v7[1]);
    if ( *((_BYTE *)v7 + 8) )
      sub_5638A0((float *)v7);
    (*(void (__thiscall **)(int *))(*v7 + 4))(v7);
  }
  v8 = byte_B69A09;
  if ( dword_B6BF8C && ((dword_B698E8 & 1) == 0 || (byte_B69A09 & 2) == 0) && !byte_B6F118 )
  {
    if ( dword_B710B0 != 1 )
    {
      v16 = dword_B7108C == 0;
      sub_4762A0(dword_B71078, &v16);
      goto LABEL_33;
    }
    v16 = dword_B7108C + 1;
    if ( dword_B7108C == 2 )
    {
      v16 = 0;
    }
    else if ( dword_B7108C != -1 )
    {
LABEL_31:
      sub_4762A0(dword_B71078, &v16);
LABEL_33:
      v8 = byte_B69A09;
      goto LABEL_34;
    }
    *((_DWORD *)this + 2) = 0;
    goto LABEL_31;
  }
LABEL_34:
  if ( dword_B6BFB8 && ((dword_B698E8 & 1) == 0 || (v8 & 2) == 0) && !byte_B6F118 )
  {
    v9 = byte_B71982;
    v10 = byte_B71980 == 0;
    byte_B71980 = byte_B71980 == 0;
    if ( (unsigned __int8)byte_B71980 < (unsigned __int8)byte_B71982
      || (v9 = byte_B71983, v10 > (unsigned __int8)byte_B71983) )
    {
      byte_B71980 = v9;
    }
  }
  if ( *((_BYTE *)this + 264) )
  {
    v11 = (int *)*((_DWORD *)this + 56);
    if ( v11 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*v11 + 24))(*((_DWORD *)this + 56)) )
        sub_562E30((float *)&dword_FAE988, v11[1]);
      if ( *((_BYTE *)v11 + 8) )
        sub_5638A0((float *)v11);
      (*(void (__thiscall **)(int *))(*v11 + 4))(v11);
    }
  }
  if ( *((_BYTE *)this + 265) )
  {
    v12 = (int *)*((_DWORD *)this + 57);
    if ( v12 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*v12 + 24))(*((_DWORD *)this + 57)) )
        sub_562E30((float *)&dword_FAE988, v12[1]);
      if ( *((_BYTE *)v12 + 8) )
        sub_5638A0((float *)v12);
      (*(void (__thiscall **)(int *))(*v12 + 4))(v12);
    }
  }
  if ( *((_BYTE *)this + 244) )
  {
    v13 = (int *)*((_DWORD *)this + 59);
    if ( v13 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*v13 + 24))(*((_DWORD *)this + 59)) )
        sub_562E30((float *)&dword_FAE988, v13[1]);
      if ( *((_BYTE *)v13 + 8) )
        sub_5638A0((float *)v13);
      (*(void (__thiscall **)(int *))(*v13 + 4))(v13);
    }
  }
  v14 = (int *)*((_DWORD *)this + 58);
  if ( (*(unsigned __int8 (__thiscall **)(int *))(*v14 + 24))(v14) )
    sub_562E30((float *)&dword_FAE988, v14[1]);
  if ( *((_BYTE *)v14 + 8) )
    sub_5638A0((float *)v14);
  return (*(int (__thiscall **)(int *))(*v14 + 4))(v14);
}
