void __fastcall sub_45E3D0(int a1, int a2, int a3)
{
  char *v4; // edx
  int v5; // ebx
  int v6; // eax
  int v7; // ecx
  char v8; // bl
  unsigned int v9; // kr04_4
  int v10; // [esp-4h] [ebp-110h]
  int v11; // [esp-4h] [ebp-110h]
  unsigned __int16 v12; // [esp+Eh] [ebp-FEh] BYREF
  char Buffer[16]; // [esp+10h] [ebp-FCh] BYREF
  char v14[16]; // [esp+20h] [ebp-ECh] BYREF
  _BYTE v15[32]; // [esp+30h] [ebp-DCh] BYREF
  char v16[60]; // [esp+50h] [ebp-BCh] BYREF
  char v17[125]; // [esp+8Ch] [ebp-80h] BYREF
  __int16 v18; // [esp+109h] [ebp-3h]
  char v19; // [esp+10Bh] [ebp-1h]

  switch ( a1 )
  {
    case 1:
      sub_462C80(v15);
      if ( !(unsigned __int8)sub_4641B0(v15, &v12) )
        goto LABEL_19;
      v4 = v15;
      goto LABEL_17;
    case 2:
      sub_5BABA0(a2, off_5FFAB8);
      return;
    case 3:
      Buffer[0] = 0;
      sprintf(Buffer, "%1.3f", 1.001999974250793);
      goto LABEL_24;
    case 4:
      sub_462C80(v15);
      if ( !(unsigned __int8)sub_4641B0(v15, &v12) )
        goto LABEL_19;
      Buffer[0] = 0;
      sprintf(Buffer, "%d", v12);
      v4 = Buffer;
      goto LABEL_17;
    case 5:
      sub_462C80(v15);
      if ( !(unsigned __int8)sub_4641B0(v15, &v12) )
        goto LABEL_19;
      v5 = sub_4E8DA0(v16);
      if ( !v5 )
        goto LABEL_19;
      v17[0] = byte_629120;
      memset(&v17[1], 0, 0x7Cu);
      v18 = 0;
      v19 = 0;
      v6 = sub_4E8F40(v17, 128);
      v7 = a2;
      v4 = v17;
      if ( !v6 )
        goto LABEL_18;
      sub_5BABA0(a2, v5 + 260);
      nullsub_6(v15);
      break;
    case 8:
      sub_462C80(v15);
      if ( !(unsigned __int8)sub_4641B0(v15, Buffer) )
        goto LABEL_19;
      v8 = v16[37];
      v14[0] = 0;
      LOBYTE(v12) = v16[36];
      v10 = v8 + (char)v12 + ((unsigned __int8)sub_4634F0(dword_764D70) == 0);
      sprintf(v14, "%d", v10);
      goto LABEL_16;
    case 10:
      sub_462C80(v15);
      if ( !(unsigned __int8)sub_4641B0(v15, Buffer) )
        goto LABEL_19;
      v14[0] = 0;
      v11 = v16[38] - (sub_462D10(0) != 0);
      sprintf(v14, "%d", v11);
LABEL_16:
      v4 = v14;
LABEL_17:
      v7 = a2;
LABEL_18:
      sub_5BABA0(v7, v4);
LABEL_19:
      nullsub_6(v15);
      break;
    case 11:
      if ( (unsigned __int8)sub_464400(dword_764D70) )
        sub_5BABA0(a2, aOpenplaying);
      else
        sub_5BABA0(a2, aClosedplaying);
      return;
    case 19:
      Buffer[0] = 0;
      v9 = strlen((const char *)sub_465260(0)) + 1;
      sprintf(Buffer, "%d", v9 != 1);
LABEL_24:
      sub_5BABA0(a2, Buffer);
      break;
    default:
      return;
  }
}
