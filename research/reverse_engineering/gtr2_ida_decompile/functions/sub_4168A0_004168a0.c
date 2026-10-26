void __thiscall sub_4168A0(int this)
{
  int v2; // eax
  _DWORD *v3; // edi
  _DWORD *v4; // eax
  float *v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  float *v9; // eax
  int v10; // ecx
  int v11; // edi
  int v12; // eax
  float *v13; // eax
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  int v17; // [esp+4h] [ebp-48h] BYREF
  int v18; // [esp+8h] [ebp-44h]
  int v19; // [esp+Ch] [ebp-40h]
  float v20[3]; // [esp+10h] [ebp-3Ch] BYREF
  float v21[3]; // [esp+1Ch] [ebp-30h] BYREF
  float v22[3]; // [esp+28h] [ebp-24h] BYREF
  float v23[3]; // [esp+34h] [ebp-18h] BYREF
  float v24[3]; // [esp+40h] [ebp-Ch] BYREF

  v2 = *(_DWORD *)(this + 32);
  *(_DWORD *)(this + 28) = 0;
  switch ( v2 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      if ( v2 )
      {
        switch ( v2 )
        {
          case 1:
            v3 = *(_DWORD **)(*(_DWORD *)(this + 36) + 216);
            break;
          case 2:
            v3 = *(_DWORD **)(*(_DWORD *)(this + 36) + 216);
            break;
          case 3:
            v3 = *(_DWORD **)(*(_DWORD *)(this + 36) + 216);
            break;
          case 4:
            v3 = *(_DWORD **)(*(_DWORD *)(this + 36) + 216);
            break;
          case 6:
            v3 = *(_DWORD **)(*(_DWORD *)(this + 36) + 216);
            break;
          case 5:
            v3 = *(_DWORD **)(*(_DWORD *)(this + 36) + 216);
            break;
          default:
            v3 = 0;
            break;
        }
      }
      else
      {
        v3 = *(_DWORD **)(*(_DWORD *)(this + 36) + 216);
      }
      if ( v3 )
        goto LABEL_22;
      break;
    case 7:
      v4 = *(_DWORD **)(this + 36);
      *(_DWORD *)(this + 16) = v4[3993];
      *(_DWORD *)(this + 20) = v4[3994];
      *(_DWORD *)(this + 24) = v4[3995];
      *(_DWORD *)(this + 28) = v4[4422];
      break;
    case 8:
      v3 = *(_DWORD **)(this + 36);
      if ( v3 )
      {
        if ( (*v3 & 0x10) != 0 )
        {
LABEL_22:
          sub_5DA7A0(this + 16, this + 20, this + 24);
          *(float *)(this + 28) = sqrt(sub_56C4A0(v3));
        }
        else
        {
          sub_56C0A0(v20);
          v5 = sub_401250(v21, v20, v22);
          v6 = *(_DWORD *)v5;
          v7 = *((_DWORD *)v5 + 1);
          v8 = *((_DWORD *)v5 + 2);
          v17 = v6;
          v18 = v7;
          v19 = v8;
          v9 = sub_4012D0((float *)&v17, v23, 0.5);
          v10 = *(_DWORD *)v9;
          v11 = *((_DWORD *)v9 + 1);
          v12 = *((_DWORD *)v9 + 2);
          *(_DWORD *)(this + 16) = v10;
          *(_DWORD *)(this + 20) = v11;
          *(_DWORD *)(this + 24) = v12;
          v13 = sub_401290(v20, (float *)(this + 16), v24);
          v14 = *(_DWORD *)v13;
          v15 = *((_DWORD *)v13 + 1);
          v16 = *((_DWORD *)v13 + 2);
          v17 = v14;
          v18 = v15;
          v19 = v16;
          *(float *)(this + 28) = sqrt(sub_401200((float *)&v17));
        }
      }
      break;
    default:
      return;
  }
}
