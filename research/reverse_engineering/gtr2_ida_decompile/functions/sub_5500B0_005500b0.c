int __userpurge sub_5500B0@<eax>(int a1@<ecx>, double a2@<st0>, int a3, int a4)
{
  char *v5; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  int m; // edi
  char *v10; // eax
  int result; // eax
  char Buffer[125]; // [esp+Ch] [ebp-80h] BYREF
  __int16 v13; // [esp+89h] [ebp-3h]
  char v14; // [esp+8Bh] [ebp-1h]

  switch ( a3 )
  {
    case 7:
      v5 = sub_41D840(&byte_91CC38, "Cannot Wave Green Yet");
      sub_472920((const char **)&dword_B6CB98, v5, 1);
      if ( sub_53F260((_DWORD *)dword_91E084) )
        sub_52C870(0, 1);
      break;
    case 1:
      for ( i = 0; i < dword_757C10; ++i )
        *(_DWORD *)(*(&dword_91E088 + i) + 19552) = 0;
      *((_DWORD *)off_757C18 + 4888) = 0;
      dword_9034DC = 0;
      byte_9034D2 = 0;
      dword_9034D4 = 1;
      *(_BYTE *)(a1 + 480) = 0;
      for ( j = 0; j < 104; ++j )
      {
        *(_DWORD *)(a1 + 8 * j + 484) = -2;
        *(_DWORD *)(a1 + 8 * j + 488) = -1082130432;
      }
      *(_DWORD *)(a1 + 1316) = 0;
      for ( k = 0; k < 104; ++k )
      {
        *(_DWORD *)(a1 + 8 * k + 1320) = -2;
        *(_DWORD *)(a1 + 8 * k + 1324) = -1082130432;
      }
      *(_DWORD *)(a1 + 2152) = 0;
      *(_DWORD *)(a1 + 2156) = 0;
      *(_DWORD *)(a1 + 2264) = 0;
      memset((void *)(a1 + 2160), 0xFFu, 0x68u);
      break;
    case 0:
      for ( m = 0; m < dword_757C10; ++m )
      {
        sub_52C760();
        *(_DWORD *)(*(&dword_91E088 + m) + 20840) = 1;
      }
      break;
  }
  memset(Buffer, 0, sizeof(Buffer));
  v13 = 0;
  v14 = 0;
  switch ( a3 )
  {
    case 0:
      sub_41D810(Buffer, 0x7Fu, "Green Flag!");
      break;
    case 1:
    case 2:
      sub_41D810(Buffer, 0x7Fu, "Full-Course Yellow");
      sub_4EE320(70, 0);
      break;
    case 3:
      sub_41D810(Buffer, 0x7Fu, (char *)WindowName);
      break;
    case 4:
    case 5:
      sub_41D810(Buffer, 0x7Fu, (char *)WindowName);
      break;
    case 7:
      sub_41D810(Buffer, 0x7Fu, "Green Flag!");
      break;
    case 8:
      sub_41D810(Buffer, 0x7Fu, "Red Flag Detected");
      break;
    default:
      break;
  }
  v10 = sub_41D840(&byte_91CC38, Buffer);
  sub_4730C0((int **)&dword_B6CB98, v10, 3, (int)&byte_1020304, 1084227584);
  switch ( a3 )
  {
    case 0:
    case 7:
      result = sub_430250(&dword_B640C0, 5u);
      break;
    case 8:
      result = sub_430250(&dword_B640C0, 7u);
      *(_DWORD *)(a1 + 348) = 8;
      return result;
    case 2:
      if ( byte_9034D0 )
      {
        result = sub_52B390();
        flt_9034E0 = a2;
      }
      break;
    default:
      result = sub_430250(&dword_B640C0, 6u);
      break;
  }
  *(_DWORD *)(a1 + 348) = a3;
  return result;
}
