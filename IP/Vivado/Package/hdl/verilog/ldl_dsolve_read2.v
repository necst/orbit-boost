// ==============================================================
// Generated by Vitis HLS v2024.1
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// ==============================================================

`timescale 1 ns / 1 ps 

module ldl_dsolve_read2 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_continue,
        ap_idle,
        ap_ready,
        n,
        m_axi_gmem1_AWVALID,
        m_axi_gmem1_AWREADY,
        m_axi_gmem1_AWADDR,
        m_axi_gmem1_AWID,
        m_axi_gmem1_AWLEN,
        m_axi_gmem1_AWSIZE,
        m_axi_gmem1_AWBURST,
        m_axi_gmem1_AWLOCK,
        m_axi_gmem1_AWCACHE,
        m_axi_gmem1_AWPROT,
        m_axi_gmem1_AWQOS,
        m_axi_gmem1_AWREGION,
        m_axi_gmem1_AWUSER,
        m_axi_gmem1_WVALID,
        m_axi_gmem1_WREADY,
        m_axi_gmem1_WDATA,
        m_axi_gmem1_WSTRB,
        m_axi_gmem1_WLAST,
        m_axi_gmem1_WID,
        m_axi_gmem1_WUSER,
        m_axi_gmem1_ARVALID,
        m_axi_gmem1_ARREADY,
        m_axi_gmem1_ARADDR,
        m_axi_gmem1_ARID,
        m_axi_gmem1_ARLEN,
        m_axi_gmem1_ARSIZE,
        m_axi_gmem1_ARBURST,
        m_axi_gmem1_ARLOCK,
        m_axi_gmem1_ARCACHE,
        m_axi_gmem1_ARPROT,
        m_axi_gmem1_ARQOS,
        m_axi_gmem1_ARREGION,
        m_axi_gmem1_ARUSER,
        m_axi_gmem1_RVALID,
        m_axi_gmem1_RREADY,
        m_axi_gmem1_RDATA,
        m_axi_gmem1_RLAST,
        m_axi_gmem1_RID,
        m_axi_gmem1_RFIFONUM,
        m_axi_gmem1_RUSER,
        m_axi_gmem1_RRESP,
        m_axi_gmem1_BVALID,
        m_axi_gmem1_BREADY,
        m_axi_gmem1_BRESP,
        m_axi_gmem1_BID,
        m_axi_gmem1_BUSER,
        D,
        D_stream_din,
        D_stream_num_data_valid,
        D_stream_fifo_cap,
        D_stream_full_n,
        D_stream_write
);

parameter    ap_ST_fsm_state1 = 11'd1;
parameter    ap_ST_fsm_state2 = 11'd2;
parameter    ap_ST_fsm_state3 = 11'd4;
parameter    ap_ST_fsm_state4 = 11'd8;
parameter    ap_ST_fsm_state5 = 11'd16;
parameter    ap_ST_fsm_state6 = 11'd32;
parameter    ap_ST_fsm_state7 = 11'd64;
parameter    ap_ST_fsm_state8 = 11'd128;
parameter    ap_ST_fsm_state9 = 11'd256;
parameter    ap_ST_fsm_state10 = 11'd512;
parameter    ap_ST_fsm_state11 = 11'd1024;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
input   ap_continue;
output   ap_idle;
output   ap_ready;
input  [31:0] n;
output   m_axi_gmem1_AWVALID;
input   m_axi_gmem1_AWREADY;
output  [63:0] m_axi_gmem1_AWADDR;
output  [0:0] m_axi_gmem1_AWID;
output  [31:0] m_axi_gmem1_AWLEN;
output  [2:0] m_axi_gmem1_AWSIZE;
output  [1:0] m_axi_gmem1_AWBURST;
output  [1:0] m_axi_gmem1_AWLOCK;
output  [3:0] m_axi_gmem1_AWCACHE;
output  [2:0] m_axi_gmem1_AWPROT;
output  [3:0] m_axi_gmem1_AWQOS;
output  [3:0] m_axi_gmem1_AWREGION;
output  [0:0] m_axi_gmem1_AWUSER;
output   m_axi_gmem1_WVALID;
input   m_axi_gmem1_WREADY;
output  [127:0] m_axi_gmem1_WDATA;
output  [15:0] m_axi_gmem1_WSTRB;
output   m_axi_gmem1_WLAST;
output  [0:0] m_axi_gmem1_WID;
output  [0:0] m_axi_gmem1_WUSER;
output   m_axi_gmem1_ARVALID;
input   m_axi_gmem1_ARREADY;
output  [63:0] m_axi_gmem1_ARADDR;
output  [0:0] m_axi_gmem1_ARID;
output  [31:0] m_axi_gmem1_ARLEN;
output  [2:0] m_axi_gmem1_ARSIZE;
output  [1:0] m_axi_gmem1_ARBURST;
output  [1:0] m_axi_gmem1_ARLOCK;
output  [3:0] m_axi_gmem1_ARCACHE;
output  [2:0] m_axi_gmem1_ARPROT;
output  [3:0] m_axi_gmem1_ARQOS;
output  [3:0] m_axi_gmem1_ARREGION;
output  [0:0] m_axi_gmem1_ARUSER;
input   m_axi_gmem1_RVALID;
output   m_axi_gmem1_RREADY;
input  [127:0] m_axi_gmem1_RDATA;
input   m_axi_gmem1_RLAST;
input  [0:0] m_axi_gmem1_RID;
input  [8:0] m_axi_gmem1_RFIFONUM;
input  [0:0] m_axi_gmem1_RUSER;
input  [1:0] m_axi_gmem1_RRESP;
input   m_axi_gmem1_BVALID;
output   m_axi_gmem1_BREADY;
input  [1:0] m_axi_gmem1_BRESP;
input  [0:0] m_axi_gmem1_BID;
input  [0:0] m_axi_gmem1_BUSER;
input  [63:0] D;
output  [127:0] D_stream_din;
input  [2:0] D_stream_num_data_valid;
input  [2:0] D_stream_fifo_cap;
input   D_stream_full_n;
output   D_stream_write;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg m_axi_gmem1_ARVALID;
reg[63:0] m_axi_gmem1_ARADDR;
reg[0:0] m_axi_gmem1_ARID;
reg[31:0] m_axi_gmem1_ARLEN;
reg[2:0] m_axi_gmem1_ARSIZE;
reg[1:0] m_axi_gmem1_ARBURST;
reg[1:0] m_axi_gmem1_ARLOCK;
reg[3:0] m_axi_gmem1_ARCACHE;
reg[2:0] m_axi_gmem1_ARPROT;
reg[3:0] m_axi_gmem1_ARQOS;
reg[3:0] m_axi_gmem1_ARREGION;
reg[0:0] m_axi_gmem1_ARUSER;
reg m_axi_gmem1_RREADY;
reg D_stream_write;

reg    ap_done_reg;
(* fsm_encoding = "none" *) reg   [10:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    gmem1_blk_n_AR;
wire    ap_CS_fsm_state2;
wire   [31:0] div_fu_132_p3;
reg   [31:0] div_reg_183;
reg    ap_block_state1;
wire   [29:0] empty_fu_150_p3;
reg   [29:0] empty_reg_188;
wire  signed [59:0] trunc_ln_fu_158_p4;
reg   [59:0] trunc_ln_reg_193;
wire   [63:0] zext_ln23_fu_179_p1;
wire    grp_read2_Pipeline_read_fu_74_ap_start;
wire    grp_read2_Pipeline_read_fu_74_ap_done;
wire    grp_read2_Pipeline_read_fu_74_ap_idle;
wire    grp_read2_Pipeline_read_fu_74_ap_ready;
wire    grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWVALID;
wire   [63:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWADDR;
wire   [0:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWID;
wire   [31:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWLEN;
wire   [2:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWSIZE;
wire   [1:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWBURST;
wire   [1:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWLOCK;
wire   [3:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWCACHE;
wire   [2:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWPROT;
wire   [3:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWQOS;
wire   [3:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWREGION;
wire   [0:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWUSER;
wire    grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WVALID;
wire   [127:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WDATA;
wire   [15:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WSTRB;
wire    grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WLAST;
wire   [0:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WID;
wire   [0:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WUSER;
wire    grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARVALID;
wire   [63:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARADDR;
wire   [0:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARID;
wire   [31:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARLEN;
wire   [2:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARSIZE;
wire   [1:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARBURST;
wire   [1:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARLOCK;
wire   [3:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARCACHE;
wire   [2:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARPROT;
wire   [3:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARQOS;
wire   [3:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARREGION;
wire   [0:0] grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARUSER;
wire    grp_read2_Pipeline_read_fu_74_m_axi_gmem1_RREADY;
wire    grp_read2_Pipeline_read_fu_74_m_axi_gmem1_BREADY;
wire   [127:0] grp_read2_Pipeline_read_fu_74_D_stream_din;
wire    grp_read2_Pipeline_read_fu_74_D_stream_write;
reg    grp_read2_Pipeline_read_fu_74_ap_start_reg;
wire    ap_CS_fsm_state10;
wire    ap_CS_fsm_state11;
wire  signed [63:0] sext_ln23_fu_168_p1;
wire   [31:0] p_neg_fu_92_p2;
wire   [30:0] p_lshr_fu_98_p4;
wire   [31:0] p_lshr_cast_fu_108_p1;
wire   [30:0] p_lshr_f_fu_118_p4;
wire   [0:0] tmp_fu_84_p3;
wire   [31:0] p_neg_t_fu_112_p2;
wire   [31:0] p_lshr_f_cast_fu_128_p1;
wire   [0:0] icmp_ln23_fu_140_p2;
wire   [29:0] trunc_ln23_fu_146_p1;
reg   [10:0] ap_NS_fsm;
reg    ap_ST_fsm_state1_blk;
reg    ap_ST_fsm_state2_blk;
wire    ap_ST_fsm_state3_blk;
wire    ap_ST_fsm_state4_blk;
wire    ap_ST_fsm_state5_blk;
wire    ap_ST_fsm_state6_blk;
wire    ap_ST_fsm_state7_blk;
wire    ap_ST_fsm_state8_blk;
wire    ap_ST_fsm_state9_blk;
wire    ap_ST_fsm_state10_blk;
reg    ap_ST_fsm_state11_blk;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_done_reg = 1'b0;
#0 ap_CS_fsm = 11'd1;
#0 grp_read2_Pipeline_read_fu_74_ap_start_reg = 1'b0;
end

ldl_dsolve_read2_Pipeline_read grp_read2_Pipeline_read_fu_74(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_read2_Pipeline_read_fu_74_ap_start),
    .ap_done(grp_read2_Pipeline_read_fu_74_ap_done),
    .ap_idle(grp_read2_Pipeline_read_fu_74_ap_idle),
    .ap_ready(grp_read2_Pipeline_read_fu_74_ap_ready),
    .m_axi_gmem1_AWVALID(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWVALID),
    .m_axi_gmem1_AWREADY(1'b0),
    .m_axi_gmem1_AWADDR(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWADDR),
    .m_axi_gmem1_AWID(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWID),
    .m_axi_gmem1_AWLEN(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWLEN),
    .m_axi_gmem1_AWSIZE(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWSIZE),
    .m_axi_gmem1_AWBURST(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWBURST),
    .m_axi_gmem1_AWLOCK(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWLOCK),
    .m_axi_gmem1_AWCACHE(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWCACHE),
    .m_axi_gmem1_AWPROT(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWPROT),
    .m_axi_gmem1_AWQOS(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWQOS),
    .m_axi_gmem1_AWREGION(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWREGION),
    .m_axi_gmem1_AWUSER(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_AWUSER),
    .m_axi_gmem1_WVALID(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WVALID),
    .m_axi_gmem1_WREADY(1'b0),
    .m_axi_gmem1_WDATA(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WDATA),
    .m_axi_gmem1_WSTRB(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WSTRB),
    .m_axi_gmem1_WLAST(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WLAST),
    .m_axi_gmem1_WID(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WID),
    .m_axi_gmem1_WUSER(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_WUSER),
    .m_axi_gmem1_ARVALID(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARVALID),
    .m_axi_gmem1_ARREADY(m_axi_gmem1_ARREADY),
    .m_axi_gmem1_ARADDR(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARADDR),
    .m_axi_gmem1_ARID(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARID),
    .m_axi_gmem1_ARLEN(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARLEN),
    .m_axi_gmem1_ARSIZE(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARSIZE),
    .m_axi_gmem1_ARBURST(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARBURST),
    .m_axi_gmem1_ARLOCK(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARLOCK),
    .m_axi_gmem1_ARCACHE(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARCACHE),
    .m_axi_gmem1_ARPROT(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARPROT),
    .m_axi_gmem1_ARQOS(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARQOS),
    .m_axi_gmem1_ARREGION(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARREGION),
    .m_axi_gmem1_ARUSER(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARUSER),
    .m_axi_gmem1_RVALID(m_axi_gmem1_RVALID),
    .m_axi_gmem1_RREADY(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_RREADY),
    .m_axi_gmem1_RDATA(m_axi_gmem1_RDATA),
    .m_axi_gmem1_RLAST(m_axi_gmem1_RLAST),
    .m_axi_gmem1_RID(m_axi_gmem1_RID),
    .m_axi_gmem1_RFIFONUM(m_axi_gmem1_RFIFONUM),
    .m_axi_gmem1_RUSER(m_axi_gmem1_RUSER),
    .m_axi_gmem1_RRESP(m_axi_gmem1_RRESP),
    .m_axi_gmem1_BVALID(1'b0),
    .m_axi_gmem1_BREADY(grp_read2_Pipeline_read_fu_74_m_axi_gmem1_BREADY),
    .m_axi_gmem1_BRESP(2'd0),
    .m_axi_gmem1_BID(1'd0),
    .m_axi_gmem1_BUSER(1'd0),
    .D_stream_din(grp_read2_Pipeline_read_fu_74_D_stream_din),
    .D_stream_num_data_valid(3'd0),
    .D_stream_fifo_cap(3'd0),
    .D_stream_full_n(D_stream_full_n),
    .D_stream_write(grp_read2_Pipeline_read_fu_74_D_stream_write),
    .div(div_reg_183),
    .sext_ln23(trunc_ln_reg_193)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((1'b1 == ap_CS_fsm_state11) & (grp_read2_Pipeline_read_fu_74_ap_done == 1'b1))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_read2_Pipeline_read_fu_74_ap_start_reg <= 1'b0;
    end else begin
        if ((1'b1 == ap_CS_fsm_state10)) begin
            grp_read2_Pipeline_read_fu_74_ap_start_reg <= 1'b1;
        end else if ((grp_read2_Pipeline_read_fu_74_ap_ready == 1'b1)) begin
            grp_read2_Pipeline_read_fu_74_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state1) & (1'b0 == ap_block_state1))) begin
        div_reg_183 <= div_fu_132_p3;
        empty_reg_188 <= empty_fu_150_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((m_axi_gmem1_ARREADY == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
        trunc_ln_reg_193 <= {{D[63:4]}};
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state11)) begin
        D_stream_write = grp_read2_Pipeline_read_fu_74_D_stream_write;
    end else begin
        D_stream_write = 1'b0;
    end
end

assign ap_ST_fsm_state10_blk = 1'b0;

always @ (*) begin
    if ((grp_read2_Pipeline_read_fu_74_ap_done == 1'b0)) begin
        ap_ST_fsm_state11_blk = 1'b1;
    end else begin
        ap_ST_fsm_state11_blk = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_block_state1)) begin
        ap_ST_fsm_state1_blk = 1'b1;
    end else begin
        ap_ST_fsm_state1_blk = 1'b0;
    end
end

always @ (*) begin
    if ((m_axi_gmem1_ARREADY == 1'b0)) begin
        ap_ST_fsm_state2_blk = 1'b1;
    end else begin
        ap_ST_fsm_state2_blk = 1'b0;
    end
end

assign ap_ST_fsm_state3_blk = 1'b0;

assign ap_ST_fsm_state4_blk = 1'b0;

assign ap_ST_fsm_state5_blk = 1'b0;

assign ap_ST_fsm_state6_blk = 1'b0;

assign ap_ST_fsm_state7_blk = 1'b0;

assign ap_ST_fsm_state8_blk = 1'b0;

assign ap_ST_fsm_state9_blk = 1'b0;

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) & (grp_read2_Pipeline_read_fu_74_ap_done == 1'b1))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = ap_done_reg;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) & (grp_read2_Pipeline_read_fu_74_ap_done == 1'b1))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        gmem1_blk_n_AR = m_axi_gmem1_ARREADY;
    end else begin
        gmem1_blk_n_AR = 1'b1;
    end
end

always @ (*) begin
    if (((m_axi_gmem1_ARREADY == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
        m_axi_gmem1_ARADDR = sext_ln23_fu_168_p1;
    end else if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARADDR = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARADDR;
    end else begin
        m_axi_gmem1_ARADDR = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARBURST = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARBURST;
    end else begin
        m_axi_gmem1_ARBURST = 2'd0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARCACHE = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARCACHE;
    end else begin
        m_axi_gmem1_ARCACHE = 4'd0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARID = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARID;
    end else begin
        m_axi_gmem1_ARID = 1'd0;
    end
end

always @ (*) begin
    if (((m_axi_gmem1_ARREADY == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
        m_axi_gmem1_ARLEN = zext_ln23_fu_179_p1;
    end else if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARLEN = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARLEN;
    end else begin
        m_axi_gmem1_ARLEN = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARLOCK = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARLOCK;
    end else begin
        m_axi_gmem1_ARLOCK = 2'd0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARPROT = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARPROT;
    end else begin
        m_axi_gmem1_ARPROT = 3'd0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARQOS = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARQOS;
    end else begin
        m_axi_gmem1_ARQOS = 4'd0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARREGION = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARREGION;
    end else begin
        m_axi_gmem1_ARREGION = 4'd0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARSIZE = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARSIZE;
    end else begin
        m_axi_gmem1_ARSIZE = 3'd0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARUSER = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARUSER;
    end else begin
        m_axi_gmem1_ARUSER = 1'd0;
    end
end

always @ (*) begin
    if (((m_axi_gmem1_ARREADY == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
        m_axi_gmem1_ARVALID = 1'b1;
    end else if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_ARVALID = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_ARVALID;
    end else begin
        m_axi_gmem1_ARVALID = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state11) | (1'b1 == ap_CS_fsm_state10))) begin
        m_axi_gmem1_RREADY = grp_read2_Pipeline_read_fu_74_m_axi_gmem1_RREADY;
    end else begin
        m_axi_gmem1_RREADY = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (1'b0 == ap_block_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((m_axi_gmem1_ARREADY == 1'b1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state5 : begin
            ap_NS_fsm = ap_ST_fsm_state6;
        end
        ap_ST_fsm_state6 : begin
            ap_NS_fsm = ap_ST_fsm_state7;
        end
        ap_ST_fsm_state7 : begin
            ap_NS_fsm = ap_ST_fsm_state8;
        end
        ap_ST_fsm_state8 : begin
            ap_NS_fsm = ap_ST_fsm_state9;
        end
        ap_ST_fsm_state9 : begin
            ap_NS_fsm = ap_ST_fsm_state10;
        end
        ap_ST_fsm_state10 : begin
            ap_NS_fsm = ap_ST_fsm_state11;
        end
        ap_ST_fsm_state11 : begin
            if (((1'b1 == ap_CS_fsm_state11) & (grp_read2_Pipeline_read_fu_74_ap_done == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state11;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign D_stream_din = grp_read2_Pipeline_read_fu_74_D_stream_din;

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state10 = ap_CS_fsm[32'd9];

assign ap_CS_fsm_state11 = ap_CS_fsm[32'd10];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

always @ (*) begin
    ap_block_state1 = ((ap_done_reg == 1'b1) | (ap_start == 1'b0));
end

assign div_fu_132_p3 = ((tmp_fu_84_p3[0:0] == 1'b1) ? p_neg_t_fu_112_p2 : p_lshr_f_cast_fu_128_p1);

assign empty_fu_150_p3 = ((icmp_ln23_fu_140_p2[0:0] == 1'b1) ? trunc_ln23_fu_146_p1 : 30'd0);

assign grp_read2_Pipeline_read_fu_74_ap_start = grp_read2_Pipeline_read_fu_74_ap_start_reg;

assign icmp_ln23_fu_140_p2 = (($signed(p_lshr_f_fu_118_p4) > $signed(31'd0)) ? 1'b1 : 1'b0);

assign m_axi_gmem1_AWADDR = 64'd0;

assign m_axi_gmem1_AWBURST = 2'd0;

assign m_axi_gmem1_AWCACHE = 4'd0;

assign m_axi_gmem1_AWID = 1'd0;

assign m_axi_gmem1_AWLEN = 32'd0;

assign m_axi_gmem1_AWLOCK = 2'd0;

assign m_axi_gmem1_AWPROT = 3'd0;

assign m_axi_gmem1_AWQOS = 4'd0;

assign m_axi_gmem1_AWREGION = 4'd0;

assign m_axi_gmem1_AWSIZE = 3'd0;

assign m_axi_gmem1_AWUSER = 1'd0;

assign m_axi_gmem1_AWVALID = 1'b0;

assign m_axi_gmem1_BREADY = 1'b0;

assign m_axi_gmem1_WDATA = 128'd0;

assign m_axi_gmem1_WID = 1'd0;

assign m_axi_gmem1_WLAST = 1'b0;

assign m_axi_gmem1_WSTRB = 16'd0;

assign m_axi_gmem1_WUSER = 1'd0;

assign m_axi_gmem1_WVALID = 1'b0;

assign p_lshr_cast_fu_108_p1 = p_lshr_fu_98_p4;

assign p_lshr_f_cast_fu_128_p1 = p_lshr_f_fu_118_p4;

assign p_lshr_f_fu_118_p4 = {{n[31:1]}};

assign p_lshr_fu_98_p4 = {{p_neg_fu_92_p2[31:1]}};

assign p_neg_fu_92_p2 = (32'd0 - n);

assign p_neg_t_fu_112_p2 = (32'd0 - p_lshr_cast_fu_108_p1);

assign sext_ln23_fu_168_p1 = trunc_ln_fu_158_p4;

assign tmp_fu_84_p3 = n[32'd31];

assign trunc_ln23_fu_146_p1 = div_fu_132_p3[29:0];

assign trunc_ln_fu_158_p4 = {{D[63:4]}};

assign zext_ln23_fu_179_p1 = empty_reg_188;

endmodule //ldl_dsolve_read2