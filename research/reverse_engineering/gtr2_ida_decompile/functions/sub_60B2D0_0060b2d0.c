int __thiscall sub_60B2D0(void *this, int a2, int a3, int a4)
{
  int v5; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char v16; // [esp+0h] [ebp-10h]

  if ( (a4 & 1) != 0 && (sub_60AF20(a2, a3, 1), v5) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating geometry stream", v16);
    return -1;
  }
  else if ( (a4 & 2) != 0 && (sub_60AF20(a2, a3, 2), v7) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating bone stream", v16);
    return -1;
  }
  else if ( (a4 & 4) != 0 && (sub_60AF20(a2, a3, 4), v8) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating bump stream", v16);
    return -1;
  }
  else if ( (a4 & 0x10) != 0 && (sub_60AF20(a2, a3, 16), v9) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating texture 0 stream", v16);
    return -1;
  }
  else if ( (a4 & 0x20) != 0 && (sub_60AF20(a2, a3, 32), v10) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating texture 1 stream", v16);
    return -1;
  }
  else if ( (a4 & 0x1000) != 0 && (sub_60AF20(a2, a3, 4096), v11) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating world vertex stream", v16);
    return -1;
  }
  else if ( (a4 & 0x8000) != 0 && (sub_60AF20(a2, a3, 0x8000), v12) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating world bump vertex stream", v16);
    return -1;
  }
  else if ( (a4 & 0x2000) != 0 && (sub_60AF20(a2, a3, 0x2000), v13) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating screen vertex stream", v16);
    return -1;
  }
  else if ( (a4 & 0x4000) != 0 && (sub_60AF20(a2, a3, 0x4000), v14) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating projected vertex stream", v16);
    return -1;
  }
  else if ( (a4 & 0x20000) != 0 && (sub_60AF20(a2, a3, 0x20000), v15) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating lworld vertex stream", v16);
    return -1;
  }
  else
  {
    return 0;
  }
}
