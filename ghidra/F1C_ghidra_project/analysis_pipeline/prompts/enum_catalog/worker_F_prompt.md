# WORKER F — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker F of 20, items 1656–1986.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_F.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

1656. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401130__FUN_00401130.c
1657. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004046b0__FUN_004046b0.c
1658. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404ef0__FUN_00404ef0.c
1659. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405880__FUN_00405880.c
1660. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004064b0__sub_4064B0.c
1661. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004072e0__FUN_004072e0.c
1662. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004081e0__FUN_004081e0.c
1663. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408868__sub_408868.c
1664. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b030__sub_40B030.c
1665. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c540__FUN_0040c540.c
1666. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d290__FUN_0040d290.c
1667. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040de60__FUN_0040de60.c
1668. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ec70__FUN_0040ec70.c
1669. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004109d0__FUN_004109d0.c
1670. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004119d0__FUN_004119d0.c
1671. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414160__FUN_00414160.c
1672. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415060__FUN_00415060.c
1673. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004186a0__FUN_004186a0.c
1674. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004190c0__FUN_004190c0.c
1675. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ad80__FUN_0041ad80.c
1676. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ed30__FUN_0041ed30.c
1677. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004203f0__FUN_004203f0.c
1678. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421a30__FUN_00421a30.c
1679. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423ca0__FUN_00423ca0.c
1680. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004263eb__FUN_004263eb.c
1681. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042acd0__FUN_0042acd0.c
1682. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bbd0__FUN_0042bbd0.c
1683. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042dd00__FUN_0042dd00.c
1684. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ed50__FUN_0042ed50.c
1685. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431d40__FUN_00431d40.c
1686. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00432e50__FUN_00432e50.c
1687. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434290__FUN_00434290.c
1688. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00435e00__FUN_00435e00.c
1689. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00438cc0__FUN_00438cc0.c
1690. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043e980__FUN_0043e980.c
1691. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00441f00__FUN_00441f00.c
1692. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447774__sub_447774.c
1693. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004486e0__FUN_004486e0.c
1694. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004499e0__FUN_004499e0.c
1695. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044b090__FUN_0044b090.c
1696. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c740__FUN_0044c740.c
1697. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cab4__sub_44CAB4.c
1698. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cd40__FUN_0044cd40.c
1699. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cfb0__FUN_0044cfb0.c
1700. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d2f4__sub_44D2F4.c
1701. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d6a0__FUN_0044d6a0.c
1702. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044da60__FUN_0044da60.c
1703. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044de20__FUN_0044de20.c
1704. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e1e0__FUN_0044e1e0.c
1705. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e5a0__FUN_0044e5a0.c
1706. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e960__FUN_0044e960.c
1707. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ee00__FUN_0044ee00.c
1708. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f73c__sub_44F73C.c
1709. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004530a0__FUN_004530a0.c
1710. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00455fd0__FUN_00455fd0.c
1711. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004579c0__FUN_004579c0.c
1712. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004594d0__FUN_004594d0.c
1713. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b5c0__FUN_0045b5c0.c
1714. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045be70__FUN_0045be70.c
1715. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c7e0__FUN_0045c7e0.c
1716. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d530__FUN_0045d530.c
1717. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00460c60__FUN_00460c60.c
1718. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461ed0__FUN_00461ed0.c
1719. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004627c0__FUN_004627c0.c
1720. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463760__FUN_00463760.c
1721. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464930__FUN_00464930.c
1722. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464fd0__FUN_00464fd0.c
1723. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466250__FUN_00466250.c
1724. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004673b0__FUN_004673b0.c
1725. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00469dd0__FUN_00469dd0.c
1726. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046ba20__FUN_0046ba20.c
1727. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d6a0__FUN_0046d6a0.c
1728. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046f170__FUN_0046f170.c
1729. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470400__sub_470400.c
1730. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471860__FUN_00471860.c
1731. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004733a0__FUN_004733a0.c
1732. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474ab0__FUN_00474ab0.c
1733. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476030__FUN_00476030.c
1734. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476fc0__FUN_00476fc0.c
1735. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478090__FUN_00478090.c
1736. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478ed0__FUN_00478ed0.c
1737. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479970__FUN_00479970.c
1738. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a190__FUN_0047a190.c
1739. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047b1b0__FUN_0047b1b0.c
1740. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c770__sub_47C770.c
1741. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f006__sub_47F006.c
1742. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485600__FUN_00485600.c
1743. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486010__FUN_00486010.c
1744. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486580__FUN_00486580.c
1745. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004870e0__FUN_004870e0.c
1746. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487720__FUN_00487720.c
1747. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004888f0__FUN_004888f0.c
1748. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489530__FUN_00489530.c
1749. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048a240__FUN_0048a240.c
1750. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b910__FUN_0048b910.c
1751. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048cc20__FUN_0048cc20.c
1752. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d850__sub_48D850.c
1753. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e860__FUN_0048e860.c
1754. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fc10__FUN_0048fc10.c
1755. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004902c0__FUN_004902c0.c
1756. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491280__FUN_00491280.c
1757. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491c70__FUN_00491c70.c
1758. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494900__FUN_00494900.c
1759. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004950e0__FUN_004950e0.c
1760. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495a80__FUN_00495a80.c
1761. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497240__FUN_00497240.c
1762. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004979e0__FUN_004979e0.c
1763. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498730__FUN_00498730.c
1764. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498f70__FUN_00498f70.c
1765. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499660__FUN_00499660.c
1766. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499b50__FUN_00499b50.c
1767. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499ea0__FUN_00499ea0.c
1768. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a3b0__FUN_0049a3b0.c
1769. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049adb0__FUN_0049adb0.c
1770. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b8d0__FUN_0049b8d0.c
1771. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d320__FUN_0049d320.c
1772. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e760__FUN_0049e760.c
1773. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f530__FUN_0049f530.c
1774. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0b20__FUN_004a0b20.c
1775. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a11e0__FUN_004a11e0.c
1776. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1f60__FUN_004a1f60.c
1777. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3820__FUN_004a3820.c
1778. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a55e0__FUN_004a55e0.c
1779. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a6340__FUN_004a6340.c
1780. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ae490__FUN_004ae490.c
1781. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1375__FUN_004b1375.c
1782. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1b10__FUN_004b1b10.c
1783. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2420__FUN_004b2420.c
1784. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b00__FUN_004b2b00.c
1785. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3ba0__FUN_004b3ba0.c
1786. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b44a0__FUN_004b44a0.c
1787. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b52a0__FUN_004b52a0.c
1788. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b68c0__FUN_004b68c0.c
1789. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b81a0__FUN_004b81a0.c
1790. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9810__FUN_004b9810.c
1791. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9da0__FUN_004b9da0.c
1792. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba950__FUN_004ba950.c
1793. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb460__FUN_004bb460.c
1794. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc2d0__FUN_004bc2d0.c
1795. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bdb90__FUN_004bdb90.c
1796. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bf630__FUN_004bf630.c
1797. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c0f60__FUN_004c0f60.c
1798. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2780__FUN_004c2780.c
1799. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2e20__FUN_004c2e20.c
1800. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4990__FUN_004c4990.c
1801. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5de0__FUN_004c5de0.c
1802. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7a70__FUN_004c7a70.c
1803. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c81a0__FUN_004c81a0.c
1804. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8d70__FUN_004c8d70.c
1805. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c97b0__sub_4C97B0.c
1806. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ca3e0__FUN_004ca3e0.c
1807. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ccdc0__FUN_004ccdc0.c
1808. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cefe0__FUN_004cefe0.c
1809. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1180__FUN_004d1180.c
1810. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d2450__FUN_004d2450.c
1811. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4a58__sub_4D4A58.c
1812. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7800__FUN_004d7800.c
1813. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7f20__FUN_004d7f20.c
1814. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8fb0__FUN_004d8fb0.c
1815. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dad30__FUN_004dad30.c
1816. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004db7f0__FUN_004db7f0.c
1817. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc430__FUN_004dc430.c
1818. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcfb0__FUN_004dcfb0.c
1819. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004de610__FUN_004de610.c
1820. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0db0__FUN_004e0db0.c
1821. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2540__FUN_004e2540.c
1822. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4500__FUN_004e4500.c
1823. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8010__FUN_004e8010.c
1824. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ea970__FUN_004ea970.c
1825. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee150__FUN_004ee150.c
1826. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0050__FUN_004f0050.c
1827. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1b10__FUN_004f1b10.c
1828. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6850__FUN_004f6850.c
1829. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8030__FUN_004f8030.c
1830. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8cd0__FUN_004f8cd0.c
1831. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9b70__FUN_004f9b70.c
1832. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc650__FUN_004fc650.c
1833. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ff0e0__FUN_004ff0e0.c
1834. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500210__FUN_00500210.c
1835. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00501e39__FUN_00501e39.c
1836. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005038c0__FUN_005038c0.c
1837. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005058d2__FUN_005058d2.c
1838. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507845__FUN_00507845.c
1839. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508b1d__FUN_00508b1d.c
1840. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509c20__FUN_00509c20.c
1841. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a7c5__FUN_0050a7c5.c
1842. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b1f0__FUN_0050b1f0.c
1843. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b77b__FUN_0050b77b.c
1844. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c23c__FUN_0050c23c.c
1845. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c887__FUN_0050c887.c
1846. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d57f__FUN_0050d57f.c
1847. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dd40__FUN_0050dd40.c
1848. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e3cd__FUN_0050e3cd.c
1849. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f258__sub_50F258.c
1850. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00510975__FUN_00510975.c
1851. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511887__FUN_00511887.c
1852. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005123e0__FUN_005123e0.c
1853. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513c38__FUN_00513c38.c
1854. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515417__FUN_00515417.c
1855. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051601f__FUN_0051601f.c
1856. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516c7b__FUN_00516c7b.c
1857. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517ee1__FUN_00517ee1.c
1858. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051984b__sub_51984B.c
1859. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051b154__FUN_0051b154.c
1860. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c2db__FUN_0051c2db.c
1861. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051d80a__FUN_0051d80a.c
1862. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ea5a__FUN_0051ea5a.c
1863. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f650__sub_51F650.c
1864. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052087e__sub_52087E.c
1865. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052266c__sub_52266C.c
1866. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005261ce__sub_5261CE.c
1867. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052803a__FUN_0052803a.c
1868. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052a6ec__FUN_0052a6ec.c
1869. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052df70__FUN_0052df70.c
1870. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00530050__FUN_00530050.c
1871. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005352b0__FUN_005352b0.c
1872. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536900__sub_536900.c
1873. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005389b0__FUN_005389b0.c
1874. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ad50__FUN_0053ad50.c
1875. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b6f0__FUN_0053b6f0.c
1876. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c680__FUN_0053c680.c
1877. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d2b0__FUN_0053d2b0.c
1878. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053f270__FUN_0053f270.c
1879. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541040__FUN_00541040.c
1880. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541ca0__FUN_00541ca0.c
1881. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542680__FUN_00542680.c
1882. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543a60__FUN_00543a60.c
1883. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005453a0__FUN_005453a0.c
1884. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005461b0__FUN_005461b0.c
1885. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005472d0__FUN_005472d0.c
1886. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548890__FUN_00548890.c
1887. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005492f0__FUN_005492f0.c
1888. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a730__FUN_0054a730.c
1889. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bc60__FUN_0054bc60.c
1890. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c2d0__FUN_0054c2d0.c
1891. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054e240__FUN_0054e240.c
1892. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fb40__FUN_0054fb40.c
1893. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005502c0__FUN_005502c0.c
1894. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005511a0__FUN_005511a0.c
1895. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551f10__FUN_00551f10.c
1896. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553370__FUN_00553370.c
1897. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554560__FUN_00554560.c
1898. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556220__FUN_00556220.c
1899. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005568b0__FUN_005568b0.c
1900. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557470__FUN_00557470.c
1901. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559350__FUN_00559350.c
1902. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bb50__FUN_0055bb50.c
1903. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c2e0__FUN_0055c2e0.c
1904. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d200__FUN_0055d200.c
1905. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ed10__FUN_0055ed10.c
1906. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560b60__FUN_00560b60.c
1907. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561a41__FUN_00561a41.c
1908. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005626b0__FUN_005626b0.c
1909. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005633d0__FUN_005633d0.c
1910. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564490__FUN_00564490.c
1911. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005648b0__FUN_005648b0.c
1912. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565400__FUN_00565400.c
1913. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005667b0__FUN_005667b0.c
1914. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566ee0__FUN_00566ee0.c
1915. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005679a0__thunk_FUN_0059d6a9.c
1916. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568220__FUN_00568220.c
1917. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568fa4__sub_568FA4.c
1918. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056a390__FUN_0056a390.c
1919. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056d1c0__FUN_0056d1c0.c
1920. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056f818__FUN_0056f818.c
1921. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a1b0__FUN_0057a1b0.c
1922. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a6a0__FUN_0057a6a0.c
1923. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a990__FUN_0057a990.c
1924. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057aef0__FUN_0057aef0.c
1925. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b800__FUN_0057b800.c
1926. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ca10__FUN_0057ca10.c
1927. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ea10__sub_57EA10.c
1928. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058119a__sub_58119A.c
1929. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581fd0__FUN_00581fd0.c
1930. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582f60__FUN_00582f60.c
1931. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005836a0__FUN_005836a0.c
1932. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584f90__FUN_00584f90.c
1933. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585860__FUN_00585860.c
1934. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586170__FUN_00586170.c
1935. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586aa0__FUN_00586aa0.c
1936. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587120__FUN_00587120.c
1937. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587580__FUN_00587580.c
1938. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587ac0__FUN_00587ac0.c
1939. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058803f__FUN_0058803f.c
1940. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588864____global_unwind2.c
1941. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058957a__FUN_0058957a.c
1942. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589cb5____exit.c
1943. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a32a__FUN_0058a32a.c
1944. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a935___malloc.c
1945. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b077__FUN_0058b077.c
1946. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bccf__FUN_0058bccf.c
1947. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c724__FUN_0058c724.c
1948. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dc40__FUN_0058dc40.c
1949. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e1b0___strlen.c
1950. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058fb90___strcmp.c
1951. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00590640____cintrindisp2.c
1952. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591cc6__FUN_00591cc6.c
1953. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592a9c__FUN_00592a9c.c
1954. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593c24__FUN_00593c24.c
1955. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594f3e__FUN_00594f3e.c
1956. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059567d__FUN_0059567d.c
1957. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596716__FUN_00596716.c
1958. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597321__FUN_00597321.c
1959. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005982f8__FUN_005982f8.c
1960. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598684__recv.c
1961. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598794__FUN_00598794.c
1962. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598c70__FUN_00598c70.c
1963. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005992d3__FUN_005992d3.c
1964. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059978a__FUN_0059978a.c
1965. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005998a1__FUN_005998a1.c
1966. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599d31__uflow.c
1967. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a418__Gninc.c
1968. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a8bc__FUN_0059a8bc.c
1969. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ae07__FUN_0059ae07.c
1970. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b490__FUN_0059b490.c
1971. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bf56__FUN_0059bf56.c
1972. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4a0__Unwind_0059c4a0.c
1973. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5c6__Unwind_0059c5c6.c
1974. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c68e__Unwind_0059c68e.c
1975. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7d8__Unwind_0059c7d8.c
1976. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8d0__Unwind_0059c8d0.c
1977. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca30__Unwind_0059ca30.c
1978. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb88__Unwind_0059cb88.c
1979. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cceb__Unwind_0059cceb.c
1980. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce8c__Unwind_0059ce8c.c
1981. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf94__Unwind_0059cf94.c
1982. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d09c__Unwind_0059d09c.c
1983. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1e8__Unwind_0059d1e8.c
1984. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d3a8__Unwind_0059d3a8.c
1985. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d52f__Unwind_0059d52f.c
1986. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d9b5__FUN_0059d9b5.c

## TASK
For each .c file:
1. Find switch statements — extract case values and purposes
2. Find comparisons against literal integers (if x == 3, if x < 7, etc.)
3. Find assignments of literal values to globals/struct fields
4. Group related values into enum candidates

## OUTPUT FORMAT

```
=== ENUM DISCOVERIES ===

### EnumName (new or extension of existing)
Source evidence: FUN_XXXXXXXX, FUN_YYYYYYYY
Variable: DAT_XXXXXXXX or param_1+0xNNN

| Value | Meaning | Evidence | Confidence |
|-------|---------|----------|------------|

=== MAGIC NUMBERS ===
| Value | Hex | Type | Used In | Likely Meaning |
|-------|-----|------|---------|---------------|
| 0.017453 | — | float | FUN_X | DEG_TO_RAD |
```

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_F.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.
