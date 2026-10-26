int __thiscall sub_4D8CF0(float *this, int a2)
{
  int v3; // ebp
  int v4; // esi
  int *v5; // edi
  int v6; // eax
  int v7; // eax
  const char *v8; // ecx
  const char *v9; // eax
  void *v10; // esi
  float v12; // [esp+10h] [ebp-90h]
  float v13; // [esp+10h] [ebp-90h]
  float v14; // [esp+10h] [ebp-90h]
  float v15; // [esp+14h] [ebp-8Ch]
  float v16; // [esp+14h] [ebp-8Ch]
  float v17; // [esp+14h] [ebp-8Ch]
  float v18; // [esp+18h] [ebp-88h]
  float v19; // [esp+18h] [ebp-88h]
  float v20; // [esp+1Ch] [ebp-84h]
  float v21; // [esp+1Ch] [ebp-84h]
  _BYTE v22[128]; // [esp+20h] [ebp-80h] BYREF

  v3 = 1;
  v4 = 0x80000000;
  sub_4D9030(a2);
  switch ( a2 )
  {
    case 1:
      v5 = &dword_8AD398;
      v18 = 768.0;
      v12 = 256.0;
      goto LABEL_17;
    case 2:
      v5 = &dword_8AD39C;
      v18 = 256.0;
      v12 = 512.0;
      goto LABEL_17;
    case 3:
      v5 = &dword_8AD3A0;
      v20 = 0.0;
      v18 = 0.0;
      v15 = 1280.0;
      v12 = 160.0;
      v4 = -1;
      v6 = sub_587C03(96);
      if ( v6 )
        v7 = sub_54FE10(v6);
      else
        v7 = 0;
      dword_8AD3AC = v7;
      *(_DWORD *)(v7 + 68) |= 1u;
      v8 = (const char *)dword_5EC428;
      if ( !dword_5EC428 )
        v8 = byte_5EA438;
      v9 = (const char *)dword_5EC3D8;
      if ( !dword_5EC3D8 )
        v9 = byte_5EA438;
      sub_58815F(v22, "%s%s%s", v9, v8, aHud51264Tga);
      if ( sub_550080(v22, 0, &unk_800004) )
      {
        sub_5502C0(dword_8AD3AC);
        v10 = (void *)dword_8AD3AC;
        if ( dword_8AD3AC )
        {
          j_nullsub_3(dword_8AD3AC);
          sub_587BCF(v10);
        }
        dword_8AD3AC = 0;
        v4 = 0x80000000;
      }
      goto LABEL_18;
    case 4:
      v5 = &dword_8AD3A4;
      v20 = 870.0;
      v18 = 140.0;
      v15 = 410.0;
      v12 = 220.0;
      goto LABEL_18;
    case 5:
      v5 = (int *)&flt_8AD3A8;
      v18 = 0.0;
      v12 = 50.0;
      v4 = -1;
LABEL_17:
      v20 = 0.0;
      v15 = 1280.0;
LABEL_18:
      if ( !*v5 )
      {
        sub_553980(v5, 2, 0, 32, 64);
        if ( *v5 )
        {
          v21 = v20 * this[57];
          v19 = v18 * this[58];
          v16 = v15 * this[57];
          v13 = v12 * this[58];
          sub_553650(0, v21, v19, 1.0, 0.0, 0.0, v4);
          v14 = v13 + v19;
          sub_553650(1, v21, v14, 1.0, 0.0, 1.0, v4);
          v17 = v16 + v21;
          sub_553650(2, v17, v14, 1.0, 1.0, 1.0, v4);
          sub_553650(3, v17, v19, 1.0, 1.0, 0.0, v4);
          if ( a2 == 3 )
            sub_553620(dword_8AD3AC);
          v3 = 0;
        }
      }
      break;
    default:
      return v3;
  }
  return v3;
}
