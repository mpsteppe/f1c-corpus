int __thiscall sub_493990(_DWORD *this, int a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  int v5; // ebp
  int v6; // edi
  int v7; // ecx
  char v9; // [esp+11h] [ebp-12Bh]
  char v10; // [esp+12h] [ebp-12Ah]
  char v11; // [esp+13h] [ebp-129h]
  float v12; // [esp+14h] [ebp-128h] BYREF
  float v13; // [esp+18h] [ebp-124h] BYREF
  _DWORD *v14; // [esp+1Ch] [ebp-120h]
  float v15; // [esp+20h] [ebp-11Ch] BYREF
  int v16; // [esp+24h] [ebp-118h]
  float v17; // [esp+28h] [ebp-114h] BYREF
  int v18; // [esp+2Ch] [ebp-110h]
  int v19; // [esp+30h] [ebp-10Ch]
  float v20; // [esp+34h] [ebp-108h]
  int v21; // [esp+38h] [ebp-104h]
  _BYTE v22[125]; // [esp+3Ch] [ebp-100h] BYREF
  __int16 v23; // [esp+B9h] [ebp-83h]
  char v24; // [esp+BBh] [ebp-81h]
  _BYTE v25[128]; // [esp+BCh] [ebp-80h] BYREF

  v22[0] = byte_5EA438[0];
  memset(&v22[1], 0, 0x7Cu);
  v23 = 0;
  v3 = 0;
  v4 = 0;
  v24 = 0;
  v5 = 0;
  v6 = this[101] + 1;
  v14 = this;
  v19 = 0;
  v16 = 0;
  v20 = 0.0;
  v21 = 0;
  v18 = 0;
  v12 = 0.0;
  v13 = 0.0;
  v17 = 0.0;
  v15 = 0.0;
  this[101] = v6;
  v9 = 0;
  v11 = 0;
  v10 = 0;
  if ( !sub_491FB0(this) )
    goto LABEL_29;
  do
  {
    if ( sub_587C20(&unk_7CDB70, asc_5CC4F4) )
    {
      if ( --v16 <= 0 )
        break;
LABEL_20:
      if ( !v9 )
        continue;
      goto LABEL_21;
    }
    if ( sub_587C20(&unk_7CDB70, asc_5CC4F8) )
    {
      ++v16;
      goto LABEL_20;
    }
    if ( sub_565870(aLocation, &v12, &v13, &v17, &v15, 0, 0, 0, 0) )
    {
      v4 = CRTFtol(v12);
      v5 = CRTFtol(v13);
      v3 = CRTFtol(v17);
      v19 = CRTFtol(v15);
      v9 = 1;
    }
    else
    {
      if ( !sub_565870(aPosWH, &v12, &v13, &v17, &v15, 0, 0, 0, 0) )
      {
        if ( sub_5654A0(aSurface, v25) )
        {
          v11 = 1;
        }
        else if ( sub_5654A0(aAnimdelta, v22) )
        {
          v20 = sub_58850F(v22);
        }
        else if ( sub_5654A0(aAnimrule, v22) )
        {
          v21 = sub_587ECE(v22);
        }
        else if ( sub_5654A0(aSubanimframe, v22) && v10 )
        {
          sub_493990(a2, v18);
        }
        goto LABEL_20;
      }
      v4 = CRTFtol(v13);
      v5 = CRTFtol(v15 + v13);
      v3 = CRTFtol(v12);
      v19 = CRTFtol(v17 + v12);
      v9 = 1;
    }
LABEL_21:
    if ( v11 && !v10 )
    {
      v18 = sub_499F70(v4, v5, v3, v19, v25, 0, 1, a3);
      v10 = 1;
    }
  }
  while ( sub_491FB0(v14) );
  v7 = v18;
  if ( v18 )
  {
    if ( v20 > 0.0 )
      *(float *)(v18 + 24) = v20;
    *(_DWORD *)(v7 + 28) = v21;
  }
LABEL_29:
  --v14[101];
  return 0;
}

