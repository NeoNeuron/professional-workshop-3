# 专业研讨课(3) 教学大纲

*2020年秋季学期*

**课程目标**： 介绍传统与新兴的计算神经科学相关的研究工具，其相关的发展现状，以及如何运用他们帮助我们更好的理解大脑。课程主要正对模型选取、模型搭建，模型评价，以及理解模型如何与我们关注的生物问题建立联系。

**课程形式**：10周课程+小组Project大作业

- 20 mins - Intro Lecture
- 1 hour - In-class coding and peer discussion
- 10 mins - Outro Lecture

**课程成绩**

- 30% - 平时作业 
- 50% - Project 大作业 (Project Report)
- 20% - 平时出勤与期末反馈

**注意事项**

- 平时作业禁止抄袭。
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

# 课程材料

- [**Tutorials**: notebooks and slides](./tutorials/README.md)
- **Materials of computational neuroscience**:
  1. [*“Neuronal Dynamics: From single neurons to networks and models of cognition”*](https://neuronaldynamics.epfl.ch/online/index.html) by Wulfram Gerstner et al.
  1. [*“Spiking Neuron Models: single neurons, populations, plasticity”*](https://www.semanticscholar.org/paper/Spiking-Neuron-Models%3A-Single-Neurons%2C-Populations%2C-Gerstner-Kistler/849f849f647bc8d49c025dc408f4e927e12bceec) by Wulfram Gerstner and Werner Kistler.
  1. [*"Theoretical Neuroscience"*](http://www.gatsby.ucl.ac.uk/~lmate/biblio/dayanabbott.pdf) by Peter Dayan and Larry F. Abbott.
  1. [*NEURON*](https://neuron.yale.edu/neuron/) simulation package.

# 课程大纲 (实际内容根据课程进度可能调整)

* [Week 0: Python Workshop](#week-0-python-workshop)
* [Week 1: Model Types](#week-1-model-types)
* [Week 2: Single Neuron Models](#week-2-single-neuron-models)
* [Week 3: Dynamical System](#week-3-dynamical-system)
* [Week 4: Model Practice 1](#week-4-model-practice-1)
* [Week 5: Model Fitting](#week-5-model-fitting)
* [Week 6: Model Practice 2](#week-6-model-practice-2)
* [Week 7: Dimensionality Reduction](#week-7-dimensionality-reduction)
* [Week 8: Bayesian Statistics](#week-8-bayesian-statistics)
* [Week 9: Network Causality](#week-9-network-causality)
* [Week 10: CNN and Autoencoder](#week-10-cnn-and-autoencoder)


### Week 0: Python Workshop

**Description:** Two workshop for absolute Python beginners. Learn essential Python skills for course tutorials and practice by coding a neuronal simulation.

### Week 1: Model Types

**Description:** Introduce different example model types (Marr 1-3, what/how/why) and the kinds of questions they can answer. Realize how different models map onto different datasets.

| Lecture   | Details                                                         |
|-----------|-----------------------------------------------------------------|
| Intro     | Model classifications, and merits of different type of models.  |
| Tutorials | "What"/"How"/"Why" models                                       |
| Outro     | Recap session, The role of models in discovery.                 |

----

### Week 2: Single Neuron Models

**Description:** The things neurons are made of, channels, morphologies, neuromodulators, and plasticity

| Lecture   |    Details                                                            |
| ----------| --------------------------------------------------------------------- |
| Intro     |    Introduction to HH neuron model.                                   |
| Tutorials |    Reduced neuron models (LIF), synapses dynamics, and plasticity.    |
| Outro     |    Recap session, A variety of neuron models                          |

----

### Week 3: Dynamical System

**Description:** How to make estimates over time, how the brain does it. How single neurons create population dynamics

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     | Phase plane analysis of HH dynamics.                         |
| Tutorials | Linear systems theory, 2D dynamical systems, Wilson-Cowen model (coarse-grained), oscillations & synchrony. <br>**Bonus:** Attractors & local linearization around fixed points, Balanced Amplification & Inhibition-stabilized network. |
| Outro     | Recap session, Linear systems rule the world. A theory of the whole brain. |

----

### Week 4: Model Practice 1

**Description:** Introduction to computational neuroscience and dendritic computation. Project introduction.

| Lecture | Details                                                      |
| ------- | ------------------------------------------------------------ |
| Keynote | Introduction to computational neuroscience and dendritic computation. Tutorial to NEURON software and PyTorch ANN. |

----

### Week 5: Model Fitting

**Description:** Fit models to data, quantify uncertainty, compare models.  The commonly used approaches, how to avoid false positives, how to do it well. 

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     | Why and how to fit models. How to predict neuronal activity with given data. |
| Tutorials | Linear regression. Get error bars with bootstrapping. Multi-dimensional linear regression and polynomial regression, and compare models, cross-validation, hyperparameters. |
| Outro     | Recap session, Critical evaluation of model fitting          |

----

### Week 6: Model Practice 2

**Description:** Introduction to the process of building models. Project introduction.

| Lecture | Details                                                      |
| ------- | ------------------------------------------------------------ |
| Keynote | Compressive Sensing in spiking neuronal networks, a demonstration of the modeling process. Tutorial to Brian2 package. |

----
### Week 7: Dimensionality Reduction

**Description:** Concept of dimensionality reduction, ways of doing it, what it means.

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     | Manifolds to understand.                                     |
| Tutorials | PCA: orthonormal basis, eigenvalues. MNIST with PCA, MNIST with t-SNE. |
| Outro     | Recap session, The link between high-dimensional brain signals and low-dimensional behavior. |

----

### Week 8: Bayesian Statistics

**Description** Bayesian statistics, modeling of behavior, modeling of neural data, quantifying information

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     | Uncertainty in signal detection theory of visual search.     |
| Tutorials | Bayes rule: cue combination and marginalization. Bayesian Decision Theory & Causal inference. |
| Outro     | Recap session, Advanced Bayesian methods                     |

----
### Week 9: Network Causality

**Description:** Ways of discovering causal relations, ways of estimating networks, what we can do with networks

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     | Causality - tools for causal inference.                      |
| Tutorials | Pittfalls of Granger and Centrality. Instrumental Variables and interventions |
| Outro     | Recap session, Ladders of causality                          |

----

### Week 10: CNN and Autoencoder

**Description:** The concept of ANNs, how to train them,what they are made out of, convnets, and how to fit them to brains. Dimension reduction using deep learning, and autoencoders for structure discovery.

| Lecture   | Details                                                      |
| --------- | ------------------------------------------------------------ |
| Intro     | Deep Learning 101. Predicting neuronal data with DL. DL for structure. |
| Tutorials | Pytorch intro & Structure of ANN and how to train it. <br>CNN, Fit to brain (RSA - represenatational similarity analysis).<br>Variational autoencorders and uses in Neuroscience. |
| Outro     | Recap session, Promises and pitfalls of ML for Neuroscience. Application of DL autoencoders |

----
