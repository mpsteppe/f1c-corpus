void __thiscall sub_4643C0(_DWORD **this)
{
  int v2; // edx
  int v3; // eax
  LPVOID *v4; // esi
  int v5; // eax
  char *v6; // eax
  int v7; // ecx
  _DWORD *v8; // eax
  LPVOID *v9; // ebp
  bool v10; // zf
  _DWORD *v11; // esi
  _DWORD *v12; // ecx
  int v13; // edx
  LPVOID *v14; // edi
  LPVOID *v15; // [esp-Ch] [ebp-18h]
  char v16; // [esp+7h] [ebp-5h]
  float v17; // [esp+8h] [ebp-4h]

  v2 = (int)*this;
  v3 = (*this)[4081];
  if ( !v3 )
    return;
  v17 = dbl_8AFE98;
  if ( v3 != 2 && v3 != 1 )
  {
    v16 = 0;
LABEL_6:
    *(float *)(v2 + 904) = v17 + *(float *)(v2 + 904);
    goto LABEL_7;
  }
  v16 = 1;
  if ( StructFieldReadAt0x3e14(this) > 1 )
    goto LABEL_6;
LABEL_7:
  if ( SingleDelegationCall_a900((*this)[4078]) )
  {
    ClearPlayerSlots(*this, 0);
    NetCommPlayerSlotSync(*this);
    ClientGridDisplayTimer((int)*this);
    CollisionContactBufferTimestepUpdate(*this + 26864, v17);
    CollisionContactIteration((int)*this);
    TrackOpeningProgressTimer((int)*this);
    if ( *((_BYTE *)*this + 40) )
    {
      SendServerOKRequest(*this);
      *((_BYTE *)*this + 40) = 0;
      if ( v16 )
      {
        if ( !*((_BYTE *)*this + 41) )
          ServerOpenTrackSignal((int)*this);
      }
    }
  }
  else
  {
    *((float *)*this + 223) = *((float *)*this + 223) - v17;
    if ( *((float *)*this + 223) < 0.0 )
    {
      GlobalStateSetter(1);
      sub_4A0DB0(&unk_7CE24D);
      sub_4A0490(&unk_7CE24C);
    }
  }
  v4 = 0;
  *((float *)*this + 225) = v17 + *((float *)*this + 225);
  v5 = (*this)[28124];
  if ( v5 )
  {
    v4 = *(LPVOID **)v5;
    v15 = *(LPVOID **)v5;
    *(_BYTE *)(v5 + 8) = 0;
    if ( !(unsigned __int8)LinkedListNodeRemoval(v15, 1) )
      v4 = 0;
  }
  if ( v4 )
  {
    do
    {
      v6 = (char *)*v4;
      if ( !*v4 )
        v6 = byte_5EA438;
      SessionStateDispatch(v6);
      if ( *v4 )
        FreeWrapper_7bcf(*v4);
      FreeWrapper_7bcf(v4);
      v7 = (*this)[28124];
      v8 = *this + 28124;
      v9 = 0;
      if ( v7 )
      {
        v9 = *(LPVOID **)v7;
        v10 = *(_DWORD *)v7 == 0;
        *(_BYTE *)(v7 + 8) = 0;
        if ( v10 || (v11 = (_DWORD *)*v8, v12 = 0, !*v8) )
        {
LABEL_27:
          v9 = 0;
        }
        else
        {
          while ( (LPVOID *)*v11 != v9 )
          {
            v12 = v11;
            v11 = (_DWORD *)v11[1];
            if ( !v11 )
              goto LABEL_27;
          }
          if ( v11 == (_DWORD *)v8[2] )
            v8[2] = v11[1];
          v13 = v11[1];
          if ( v12 )
            v12[1] = v13;
          else
            *v8 = v13;
          if ( (_DWORD *)v8[1] == v11 )
            v8[1] = v12;
          --v8[3];
          if ( *((_BYTE *)v11 + 8) )
          {
            v14 = (LPVOID *)*v11;
            if ( *v11 )
            {
              if ( *v14 )
                FreeWrapper_7bcf(*v14);
              FreeWrapper_7bcf(v14);
            }
          }
          FreeWrapper_7bcf(v11);
        }
      }
      v4 = v9;
    }
    while ( v9 );
  }
  if ( v16 )
    StringLengthCheckDispatch((_BYTE *)*this + 112528);
  MouseInputHandler((float *)*this);
}

