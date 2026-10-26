int __thiscall sub_4B8E50(_DWORD *this)
{
  char *v2; // eax
  _DWORD *v3; // ecx
  int v4; // eax
  _BYTE v6[125]; // [esp+8h] [ebp-80h] BYREF
  __int16 v7; // [esp+85h] [ebp-3h]
  char v8; // [esp+87h] [ebp-1h]

  memset(v6, 0, sizeof(v6));
  v7 = 0;
  v8 = 0;
  v2 = sub_41D840(&byte_91CC38, "No Controller Detected");
  sub_630FE0(v6, v2, 127);
  v8 = 0;
  sub_409FB0(this + 13);
  switch ( this[69] )
  {
    case 1:
      sub_4D3CF0("KEYBOARD", -1);
      goto LABEL_3;
    case 2:
LABEL_3:
      v3 = &unk_B6A474;
      goto LABEL_6;
    case 3:
      v3 = &unk_B6A878;
      goto LABEL_6;
    case 4:
      v3 = &unk_B6AC7C;
LABEL_6:
      v4 = sub_45DC60(v3);
      sub_4D3CF0(v4, -1);
      break;
    default:
      return 0;
  }
  return 0;
}
