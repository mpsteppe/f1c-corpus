const char **__thiscall sub_4331B0(int this, const char **a2)
{
  const char **result; // eax
  int v4; // esi
  char *v5; // eax
  const char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  double v9; // st7
  bool v10; // cc
  char *v11; // eax
  int v12; // ebx
  unsigned __int64 v13; // rax
  char *v14; // eax
  char *v15; // eax
  int v16; // eax
  const char *v17; // edi
  int v18; // eax
  char *v19; // esi
  double v20; // st7
  double v21; // st7
  int v22; // eax
  double v23; // st7
  int v24; // eax
  int v25; // edx
  double v26; // st7
  char *v27; // esi
  int v28; // [esp+10h] [ebp-68h]
  int v29; // [esp+14h] [ebp-64h]
  const char *v30; // [esp+14h] [ebp-64h]
  int v31; // [esp+14h] [ebp-64h]
  char *v32; // [esp+14h] [ebp-64h]
  int v33; // [esp+20h] [ebp-58h]
  double v34; // [esp+28h] [ebp-50h]
  double v35; // [esp+28h] [ebp-50h]
  int v36; // [esp+2Ch] [ebp-4Ch]
  char Buffer[64]; // [esp+38h] [ebp-40h] BYREF

  result = a2;
  v4 = ((_DWORD)a2 << 6) + this + 2992;
  switch ( (unsigned int)a2 )
  {
    case 0u:
    case 1u:
      v5 = sub_41D840(&byte_91CC38, (const char *)&dword_6F2618);
      sprintf((char *const)(v4 + 30), v5);
      result = (const char **)sub_560950(&dword_FAE908, this + 112);
      if ( result )
      {
        result = (const char **)sub_560800(*(_DWORD *)(v4 + 20));
        if ( result )
        {
          v6 = *result;
          if ( !v6 )
            v6 = WindowName;
          v7 = sub_41D840(&byte_91CC38, v6);
          return (const char **)sprintf((char *const)(v4 + 30), v7);
        }
      }
      return result;
    case 2u:
    case 3u:
    case 0x20u:
      v9 = ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
          + *(double *)(((_DWORD)a2 << 6) + this + 2992))
         * 100.0;
      return (const char **)sprintf((char *const)(((_DWORD)a2 << 6) + this + 3022), "%4.1f:%4.1f", 100.0 - v9, v9);
    case 4u:
      v34 = (double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
          + *(double *)(((_DWORD)a2 << 6) + this + 2992);
      v8 = sub_41D840(&byte_91CC38, "turns");
      return (const char **)sprintf((char *const)(v4 + 30), "%.2f %s", v34, v8);
    case 5u:
    case 0x35u:
    case 0x36u:
    case 0x37u:
    case 0x38u:
    case 0x39u:
    case 0x3Au:
    case 0x3Bu:
    case 0x3Cu:
      if ( a2 == (const char **)53 )
      {
        v10 = *(_DWORD *)(this + 6340) < 1;
      }
      else if ( a2 == (const char **)54 )
      {
        v10 = *(_DWORD *)(this + 6340) < 2;
      }
      else if ( a2 == (const char **)55 )
      {
        v10 = *(_DWORD *)(this + 6340) < 3;
      }
      else if ( a2 == (const char **)56 )
      {
        v10 = *(_DWORD *)(this + 6340) < 4;
      }
      else if ( a2 == (const char **)57 )
      {
        v10 = *(_DWORD *)(this + 6340) < 5;
      }
      else if ( a2 == (const char **)58 )
      {
        v10 = *(_DWORD *)(this + 6340) < 6;
      }
      else if ( a2 == (const char **)59 )
      {
        v10 = *(_DWORD *)(this + 6340) < 7;
      }
      else
      {
        if ( a2 != (const char **)60 )
          goto LABEL_26;
        v10 = *(_DWORD *)(this + 6340) < 8;
      }
      if ( v10 )
        goto LABEL_66;
LABEL_26:
      v35 = (double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
          + *(double *)(((_DWORD)a2 << 6) + this + 2992);
      if ( *(double *)(this + 6936) == 0.0 )
      {
        v11 = sub_41D840(&byte_91CC38, off_6F3FD0);
        sprintf(Buffer, "(%s)", v11);
      }
      else
      {
        v12 = (unsigned __int64)(v35 * *(double *)(this + 6936));
        v13 = (unsigned __int64)((double)v12 * flt_91BDF0 * 0.016666668);
        v29 = (int)v13 % 60;
        v28 = (int)v13 / 60;
        if ( v12 == 1 )
        {
          v14 = sub_41D840(&byte_91CC38, (const char *)&off_6F3FC4);
          sprintf(Buffer, "(1 %s/ %d:%.2d)", v14, v28, v29);
        }
        else
        {
          v15 = sub_41D840(&byte_91CC38, "laps");
          sprintf(Buffer, "(%d %s/ %d:%.2d)", v12, v15, v28, v29);
        }
      }
      v16 = *(_DWORD *)(this + 4);
      v17 = (const char *)(this + 88);
      if ( v16 == 1 )
        return (const char **)sprintf((char *const)(v4 + 30), "%4.1f %s %s", v35 * 0.2641720372841846, v17, Buffer);
      v18 = sub_431910(v35);
      return (const char **)sprintf((char *const)(v4 + 30), "%d %s %s", v18, v17, Buffer);
    case 6u:
    case 7u:
      if ( *(_BYTE *)(this + 6922) )
        return (const char **)sub_432EE0((const char *)this, ((_DWORD)a2 << 6) + this + 2992, *(_BYTE *)(this + 6923));
      if ( !*(_BYTE *)(this + 6923) || *(_DWORD *)(((_DWORD)a2 << 6) + this + 3012) )
        v21 = ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
             + *(double *)(((_DWORD)a2 << 6) + this + 2992))
            * 100.0;
      else
        v21 = 0.0;
      v30 = (const char *)(this + 24);
      v19 = (char *)(((_DWORD)a2 << 6) + this + 3022);
      if ( !*(_DWORD *)(this + 4) )
        return (const char **)sprintf(v19, "%.2f %s", v21, v30);
      return (const char **)sprintf(v19, "%.3f %s", v21 * 0.3937007874015748, v30);
    case 8u:
    case 9u:
      return (const char **)sprintf(
                              (char *const)(((_DWORD)a2 << 6) + this + 3022),
                              "%.2f %s",
                              ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012)
                             * *(double *)(((_DWORD)a2 << 6) + this + 3000)
                             + *(double *)(((_DWORD)a2 << 6) + this + 2992))
                            * 57.29577951308232,
                              (const char *)(this + 40));
    case 0xAu:
    case 0xBu:
      v30 = (const char *)(this + 24);
      v19 = (char *)(((_DWORD)a2 << 6) + this + 3022);
      v20 = ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
           + *(double *)(((_DWORD)a2 << 6) + this + 2992))
          * 100.0;
      if ( !*(_DWORD *)(this + 4) )
        return (const char **)sprintf(v19, "%.1f %s", v20, v30);
      v21 = v20 * 0.3937007874015748;
      return (const char **)sprintf(v19, "%.2f %s", v21, v30);
    case 0xCu:
    case 0xDu:
    case 0x23u:
      return (const char **)sprintf(
                              (char *const)(((_DWORD)a2 << 6) + this + 3022),
                              "%.1f %s",
                              ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012)
                             * *(double *)(((_DWORD)a2 << 6) + this + 3000)
                             + *(double *)(((_DWORD)a2 << 6) + this + 2992))
                            * 57.29577951308232,
                              (const char *)(this + 40));
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x16u:
      return (const char **)sub_432FC0(this, ((_DWORD)a2 << 6) + this + 2992, 0.0);
    case 0x11u:
    case 0x17u:
      return (const char **)sub_432EE0((const char *)this, ((_DWORD)a2 << 6) + this + 2992, 0);
    case 0x12u:
    case 0x13u:
    case 0x14u:
    case 0x15u:
    case 0x18u:
    case 0x19u:
    case 0x1Au:
    case 0x1Bu:
      return (const char **)sub_432F40((const char *)this, ((_DWORD)a2 << 6) + this + 2992);
    case 0x1Cu:
    case 0x1Fu:
    case 0x27u:
    case 0x29u:
      return (const char **)sprintf(
                              (char *const)(((_DWORD)a2 << 6) + this + 3022),
                              "%d",
                              *(_DWORD *)(((_DWORD)a2 << 6) + this + 3012) + 1);
    case 0x1Du:
      if ( (*(_BYTE *)(this + 6924) & 1) != 0 )
        return (const char **)sprintf(
                                (char *const)(((_DWORD)a2 << 6) + this + 3022),
                                "%d",
                                *(_DWORD *)(((_DWORD)a2 << 6) + this + 3012) + 1);
      v22 = sub_431910(
              (double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
            + *(double *)(((_DWORD)a2 << 6) + this + 2992));
      return (const char **)sprintf((char *const)(v4 + 30), "%d %s", v22, (const char *)(this + 40));
    case 0x1Eu:
      if ( (*(_BYTE *)(this + 6924) & 2) != 0 )
        return (const char **)sprintf(
                                (char *const)(((_DWORD)a2 << 6) + this + 3022),
                                "%d",
                                *(_DWORD *)(((_DWORD)a2 << 6) + this + 3012) + 1);
      v23 = 100.0
          - ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
           + *(double *)(((_DWORD)a2 << 6) + this + 2992));
LABEL_57:
      v31 = sub_431910(v23);
      return (const char **)sprintf((char *const)(v4 + 30), "%d%%", v31);
    case 0x21u:
    case 0x22u:
    case 0x24u:
    case 0x25u:
    case 0x26u:
      v23 = ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
           + *(double *)(((_DWORD)a2 << 6) + this + 2992))
          * 100.0;
      goto LABEL_57;
    case 0x28u:
      if ( !*(_BYTE *)(this + 6920) )
        goto LABEL_66;
      v24 = sub_431910(
              ((double)*(int *)(((_DWORD)a2 << 6) + this + 3012) * *(double *)(((_DWORD)a2 << 6) + this + 3000)
             + *(double *)(((_DWORD)a2 << 6) + this + 2992))
            * 9.549296585513721);
      return (const char **)sprintf((char *const)(v4 + 30), "%d%03d", v24 / 1000, v24 % 1000);
    case 0x2Au:
    case 0x34u:
      return (const char **)sprintf(
                              (char *const)(((_DWORD)a2 << 6) + this + 3022),
                              "%d",
                              *(_DWORD *)(((_DWORD)a2 << 6) + this + 3012));
    case 0x2Bu:
      sub_4315F0();
      sub_431610();
      sub_41D840(&byte_91CC38, "bevel");
      return (const char **)off_16C9314(a2);
    case 0x2Cu:
    case 0x2Du:
    case 0x2Eu:
    case 0x2Fu:
    case 0x30u:
    case 0x31u:
    case 0x32u:
    case 0x33u:
      if ( *(_BYTE *)(((_DWORD)a2 << 6) + this + 3020) )
      {
        sub_4315B0();
        v36 = sub_4315D0();
        v26 = sub_431630((int *)(this + 6896), v25, *(_DWORD *)(this + 5764));
        v27 = (char *)(v4 + 30);
        if ( (*(_BYTE *)(this + 6924) & 4) != 0 )
          return (const char **)sprintf(v27, "%2d/%2d (%.3f)", v33, v36, v26);
        else
          return (const char **)sprintf(v27, "%.2f (%.2f)", (double)v36 / (double)v33, v26);
      }
      else
      {
LABEL_66:
        v32 = sub_41D840(&byte_91CC38, off_6F3FD0);
        return (const char **)sprintf((char *const)(v4 + 30), "%s", v32);
      }
    default:
      return result;
  }
}
