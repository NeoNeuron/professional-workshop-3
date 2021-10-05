# 专业研讨课(3) 教学大纲

*2021年秋季学期*

- [专业研讨课(3) 教学大纲](#专业研讨课3-教学大纲)
  - [预备知识](#预备知识)
    - [编程基础](#编程基础)
    - [数学基础](#数学基础)
    - [神经科学](#神经科学)
  - [课程材料](#课程材料)
  - [课程大纲 (实际顺序根据课程进度调整)](#课程大纲-实际顺序根据课程进度调整)
    - [Week 0: Python Workshop](#week-0-python-workshop)
    - [Week 1: Model Types](#week-1-model-types)
    - [Week 2: Intro to CNS, Single Neuron Models and Network Dynamics](#week-2-intro-to-cns-single-neuron-models-and-network-dynamics)
    - [Week 3: Dimensionality Reduction](#week-3-dimensionality-reduction)
    - [Week 4: Model Fitting and GLM](#week-4-model-fitting-and-glm)
    - [Week 5: Machine Learning](#week-5-machine-learning)
    - [Week 6: Network Causality](#week-6-network-causality)
    - [Week 7: Bayesian Statistics](#week-7-bayesian-statistics)
    - [Week 8: Hidden Markov Model](#week-8-hidden-markov-model)
    - [Week 9: Optimal Control](#week-9-optimal-control)
    - [Week 10: Reinforcement Learning](#week-10-reinforcement-learning)
    - [Week 10: Students Presentations (20 min each group $\times$ 4)](#week-10-students-presentations-20-min-each-group-times-4)


**课程目标**： 
这门课程以数学与生命学科，尤其是神经科学交叉为背景，着眼于交叉学科的思维能力以及数学定量的训练，通过介绍一些常用的数学、统计学等方法在神经科学中的应用，配合一些小的研究项目来培养跨学科思想以及从事交叉学科研究的基本能力。

**课程形式**：10周课程+小组Project大作业

- 30 分钟： 背景知识介绍
- 1 小时：课堂编程练习+小组讨论

**课程成绩**

- 70% - Project 大作业 (Project Report)
- 30% - 平时出勤与期末反馈

**注意事项**

- 平时课堂参与度将纳入平时出勤考核。
- 大作业以小组形式进行，每位同学需在期末报告中标注个人贡献，结合小组project完成度与个人贡献情况打分。

## 预备知识

### 编程基础

课程使用Python为主要编程语言，编程材料与联系将以Jupyter Notebook的形式呈现。

如果你从未接触过编程，或Python相关的编程练习，请从现在开始认识Python，做一些简单的练习。我们期望大家熟悉Python的变量`variable`、列表`list`、字典`dict`，以及Numpy，Scipy，Matplotlib等科学计算相关的Python package。

关于Python的零基础入门学习，我们推荐大家访问[Software carpentry 1-day Python tutorial](https://swcarpentry.github.io/python-novice-inflammation/)进行学习。其中，强烈推荐大家根据[Setup](https://swcarpentry.github.io/python-novice-inflammation/setup/)教程安装Python3版本的anaconda，方便后续的Python的使用和库管理。

学有余力或对Python进阶用法感兴趣的同学，可以进一步学习[Scipy-Lecture-Notes](https://scipy-lectures.org/)的文档，进一步了解诸如Numpy, Scipy, Matplotlib, sklearn等科学计算库的进阶用法。

**请大家自学完成[W0_PythonWorkshop](./tutorials/W0_PythonWorkshop)。**

### 数学基础

线性代数，概率统计，微积分

### 神经科学

课程主要涉及计算神经科学领域的最前沿研究问题与方法。为了更好的了解神经科学的基本框架有更好的了解，**请大家在课程开始之前观看以下视频。**

- [Introduction to Neuroscience](https://www.bilibili.com/video/BV1Kg41137Cp)
- [Human Psychophysics](https://www.bilibili.com/video/BV1Wg41137Cv)
- [Behavioral Readout](https://www.bilibili.com/video/BV1fU4y1G7jX)
- [Live in Lab](https://www.bilibili.com/video/BV1r5411T7pP)
- [Stimulus Representation](https://www.bilibili.com/video/BV1d64y1t7mP)
- [Neurotransmitters](https://www.bilibili.com/video/BV1Vy4y1M79o)
- [Neurons to Consciousness](https://www.bilibili.com/video/BV1eU4y1G7Hr)
- **Brain Signals:** [Spiking Activity](https://www.bilibili.com/video/BV1uv411H77J), [LFP](https://www.bilibili.com/video/BV17o4y1C7K4), [EEG & MEG](https://www.bilibili.com/video/BV1RV411s7kn), [fMRI](https://www.bilibili.com/video/BV1wU4y1V776), [Calcium Imaging](https://www.bilibili.com/video/BV1G44y1z7Tg)

## 课程材料

- [**Tutorials**: notebooks and slides](./tutorials/README.md)
- **Materials of computational neuroscience**:
  1. [*“Neuronal Dynamics: From single neurons to networks and models of cognition”*](https://neuronaldynamics.epfl.ch/online/index.html) by Wulfram Gerstner et al.
  1. [*“Spiking Neuron Models: single neurons, populations, plasticity”*](https://www.semanticscholar.org/paper/Spiking-Neuron-Models%3A-Single-Neurons%2C-Populations%2C-Gerstner-Kistler/849f849f647bc8d49c025dc408f4e927e12bceec) by Wulfram Gerstner and Werner Kistler.
  1. [*"Theoretical Neuroscience"*](http://www.gatsby.ucl.ac.uk/~lmate/biblio/dayanabbott.pdf) by Peter Dayan and Larry F. Abbott.
  1. [*NEURON*](https://neuron.yale.edu/neuron/) simulation package.
  1. [*Brian2*](https://briansimulator.org) simulation package.

## 课程大纲 (实际顺序根据课程进度调整)


### Week 0: Python Workshop

**Description:** Two workshop for absolute Python beginners. Learn essential Python skills for course tutorials and practice by coding a neuronal simulation.

### Week 1: Model Types

| Lecture   | Details                                                         |
|-----------|-----------------------------------------------------------------|
| Intro     | 1. Model classifications, characteristics and merits of different type of models. |
||2. Intro to each of the individual projects.  |
| Tutorials | "What"/"How"/"Why" models based on the example of ISI disributions.             |

----

### Week 2: Intro to CNS, Single Neuron Models and Network Dynamics

| Lecture   |    Details                                                            |
| ----------| --------------------------------------------------------------------- |
| Intro     |    1. Intro to computational neuroscience.                            |
||2. Introduction to LIF and HH neuron model, and network dynamics.
| Tutorials |    1. Coding to simulate LIF neuron;
|| 2. Coding to simulate LIF network model with the help of Brian2, and tune the network to reach different dynamical region;|
|Bonus | Synaptic dynamics. |

<!-- Linear systems theory, 2D dynamical systems, Wilson-Cowen model (coarse-grained), oscillations & synchrony. <br> Attractors & local linearization around fixed points, Balanced Amplification & Inhibition-stabilized network. | -->

----

### Week 3: Dimensionality Reduction

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     | 1. Low dim manifold in high dim data;|
|| 2. high-D signals and low-D behavior;
|| 3. bonus: geometric point of view for low dim manifold;                         |
|Tutorials| Practice PCA with synthatic data;|

----

### Week 4: Model Fitting and GLM

| Lecture | Details                                                      |
| ------- | ------------------------------------------------------------ |
| Intro    | 1. How to fit data with linear regression model. |
| | 2. Extend linear model to Poisson GLM to fit an encoding model to spike data.|
| | 3. Regularizations.|
| Tutorials | 1. Linear regression, multi-dimensional linear regression and polynomial regression.
| | 2. GLMs and predicting neural responses. Logistic regression, regularization, and decoding neural activity.   |
| | Bonus:  Model comparison and cross-validations. |

----

### Week 5: Machine Learning

| Lecture | Details                                                      |
| ------- | ------------------------------------------------------------ |
| Intro | 1. Application of deep learning in neuroscience; |
|| 2. Train a network to predict behavior data based on electrophysiological data.|
|| 3. Train RNN; |
| Tutorials | 1. Pytorch 101. Predicting neuronal data with with MLP. |
| | 2. Train RNN to perform behavior tasks. | 
<!-- Fit to brain (RSA - represenatational similarity analysis). Variational autoencorders and uses in Neuroscience. | -->

----

### Week 6: Network Causality

**Description:** Ways of discovering causal relations, ways of estimating networks, what we can do with networks

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     | 1. definition of and Tools for causal inference;|
|| 2. Applying GC, TDMI, TE onto neural data to infer connectivity;.                      |
| Tutorials | 1. Model based inference, and GC|
|| 2. Model free inference, TDMI, compare the performance of GC and TDMI for different synthatic data.|

----

### Week 7: Bayesian Statistics

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     | Uncertainty in signal detection theory of visual search.     |
| Tutorials | 1. Bayes with a binary hidden state.|
|| 2. Bayesian decision and inference with continuous hidden state.|

----

### Week 8: Hidden Markov Model

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     |  Combining linear dynamics and Bayesian statistics to form Hidden Markov Models (HMMs). |
| Tutorials | 1. Fishing (for a binary latent state).|
||2. Tracking astrocat (for a gaussian latent state).|
||3. Kalmann filter. |


----

### Week 9: Optimal Control

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     | Intro to optimal control by adding actions to maximize utility in previous HMM system.   |
| Tutorials | 1. Fishing example, updating your fishing location to catch the most fish. |
| | 2. Astrocat example, using the cat’s jetpack to keep the cat on target.|

----

### Week 10: Reinforcement Learning

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     | Intro to Reinforcement Learning.                        |
|Tutorials|1. how we learn the value of future states from our experience. |
||2. how to make and learn from actions and the explore-exploit dilemma. |
||3. how we can efficiently learn the future value of actions from experience. |
||4. how having a model of the world’s dynamics can help you to learn and act.|

----

### Week 10: Students Presentations (20 min each group $\times$ 4)

----
